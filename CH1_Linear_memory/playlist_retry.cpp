#include <iostream>
#include <algorithm>

using namespace std; 

struct song_info
{
    string tittle; 
    song_info* prev;
    song_info* next; 
}; 

template <typename T>
class playlist_ll
{
    private: 
        song_info* head;
        song_info* tail; 
        int size = 0; 
    public: 
        playlist_ll()
        {
            head = new song_info{"", nullptr, nullptr}; 
            tail = new song_info{"", head, head};
            head->next = tail; 
            head->prev = tail; 
        }

        song_info* find_song(string song)
        {
            int count = 0; 
            song_info* find_elem = head->next; 
            while(find_elem->tittle != song)
            {
                if(count > size) break; 
                find_elem = find_elem->next;
                count++; 
            }
            return find_elem; 
        }


        struct cir_playlist_iter //  사용자 정의 반복자  
        {
            private:
                song_info* ptr; 

            public:
                cir_playlist_iter(song_info* p) : ptr(p){} // 생성자 초기화 
            
            string& operator*(){return (ptr->tittle);}
            song_info* get(){return ptr;}
            cir_playlist_iter& operator++(){ptr = ptr->next; return *this; } // 객체를 return 
            cir_playlist_iter operator++(int){cir_playlist_iter it = *this; ++(*this); return it;} // 객체를 return 
            cir_playlist_iter& operator--(){ptr = ptr->prev; return *this; } // 객체를 return 
            cir_playlist_iter operator--(int){cir_playlist_iter it = *this; --(*this); return it;} // 객체를 return 
            friend bool operator==(const cir_playlist_iter it1, const cir_playlist_iter it2){return it1.ptr == it2.ptr;}
                        friend bool operator!=(const cir_playlist_iter it1, const cir_playlist_iter it2){return it1.ptr != it2.ptr;}
        }; 

        cir_playlist_iter begin(){return cir_playlist_iter(head);}
        cir_playlist_iter end(){return cir_playlist_iter(tail);}
        cir_playlist_iter begin() const {return cir_playlist_iter(head);}
        cir_playlist_iter end() const {return cir_playlist_iter(tail);}



        void insert(string song)
        {
            song_info* new_song = new song_info{song, head, head->next};
            head->next->prev = new_song; 
            head->next = new_song; 
            size++; 
        }

        void erase(string song)
        {
            if(head->next != tail)
            {
                song_info *temp = find_song(song); 
                if(temp != nullptr)
                {
                    temp->prev->next = temp->next; 
                    temp->next->prev = temp->prev; 
                    delete temp; 
                    size--; 
                }
            }
        }

        void Printall()
        {
            song_info* str =  head->next; 
            while(str != nullptr)
            {
                if(str == tail) 
                {
                    cout << "Keep continue [y/n]? > "; 
                    char c; 
                    cin >> c; 
                    if(c == 'n') break; 
                }

                cout << str->tittle << endl; 
                str = str->next; 
            }
        }

        playlist_ll(const playlist_ll<T>& other) : playlist_ll()
        {
            for(const auto& i : other) insert(i);
        }

        
        playlist_ll(const initializer_list<T>& li) : head(NULL), tail(NULL)
        {
            for(const auto& i : li) insert(i);
        }


        ~playlist_ll()
        {
            while(head->next != tail){erase(head->next->tittle);}
            delete head, tail;
        }
}; 


int main()
{
    playlist_ll<string> mylist; 
    mylist.insert("song 1");
    mylist.insert("song 2");
    mylist.insert("song 3"); 
    mylist.erase("song 2");
    mylist.Printall(); 

    cout << "Copy list 1" << endl; 
    playlist_ll<string> mylist2 = mylist;
    mylist2.insert("song 2");
    mylist2.Printall(); 

    cout << "Copy list 2" << endl; 
    playlist_ll<string> mylist3 = {"song 4", "song 5", "song 6"};
    for(auto& i : mylist3){ cout << i << " ";}
    return 0; 
}