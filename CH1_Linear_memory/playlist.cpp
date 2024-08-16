// // 필요한 자료형, 현재 음악의 리스트 갯수(int), 음악의 제목(string)
// // playlist; 문자열 배열 이어야 함, 


// // 기본적인 CRUD 기능, 단 Read는 무한 
// // playlist자료형은 Linked_list type 

// #include <iostream>
// #include <string>

// using namespace std; 

// // 노래 정보 
// struct node
// {
//     string tittle; 
//     node* next; 
// }; 


// class playlist
// {       
//     public: 
//         node* tail;  
//         node* head;

//         playlist(int num)
//         {
//             head = new node {"", nullptr}; 
//             tail = new node {"", nullptr}; 
//             head->next = tail;
//             tail->next = head; 
//             if(num > 0)
//             {
//                 for(int i =0; i < num; i++) insert(); 
//             }     
//         }; 

//         void insert();
//         void erase();
//         void erase(string name);
//         void play();   

//         ~playlist()
//         {
//             delete head;
//             delete tail; 
//         }; 
// };


// void playlist::insert()
// {
//     string title;   
     
//     cout << "Song tittle : "; 
//     getline(cin, title); 
    
//     node* new_node = new node {title, head->next};
//     head->next = new_node; 
// }; 

// void playlist::erase()
// {
//     node* temp = head->next; 
//     char check ; 

//     cout << "Are you sure to delete latest song[y/n] ?: "; 
//     cin >> check; 
//     if(check == 'y' && temp != tail)
//     {
//         head->next = temp->next;
//         delete temp; 
//     }
// };
    
    
//     void playlist::erase(string name)
//     {
//         node* temp = head; 

//         while(temp->next->tittle != name)
//         {
//             temp = temp->next; 
//         }

//         node* del_node = temp->next; 
//         temp->next = del_node->next; 
//         delete del_node; 
//     };
    
//     void playlist::play()
//     {
//         node* read = head; 
//         while(true)
//         {
//             if(read->tittle != "")
//             {
//                 cout << "Current: " <<  read->tittle << endl; 
//             }            
//             if(read->next == tail)
//             {
//                 cout << "You want to repeat your list[y/n]?: ";
//                 char check; 
//                 cin >> check; 
//                 if(check == 'n') 
//                 {
//                     cout << "Stop Playing list ... " << endl;  
//                     break; 
//                 }
//             }
//             read = read->next; 

//         }
//     };   

// int main()
// {
//     int size; 

//     cout << "Enter number of songs : "; 
//     cin >> size; 
//     cin.ignore(); 

//     playlist play(size);
    
//     int menu = 0; 
//     while(menu >= 0)
//     {
//         cout << endl; 
//         cout << "#1. Enter new song" <<endl;
//         cout << "#2. Erase song on the top" <<endl;
//         cout << "#3. Erase song which has same tittle" <<endl;
//         cout << "#4. Play list " <<endl; 
//         cout << "#5. exit" <<endl <<endl; 
//         cout << "Enter your menu (1 ~ 5): "; 
//         cin >> menu; 
//         cin.ignore(); 

//         if(menu == 5) break; 
//         else
//         {
//             switch(menu)
//             {
//                 case 1:
//                     play.insert(); 
//                     break;
//                 case 2: 
//                     play.erase(); 
//                     break; 
//                 case 3: 
//                 {
//                     cout << "Erase song tittle : "; 
//                     string name ; 
//                     getline(cin, name);
//                     play.erase(name); 
//                     break; 
//                 }
//                 case 4:
//                     play.play(); 
//                 default: break; 
//             }
//         }
//     }

//     return 0; 
// }

#include <iostream>
#include <string>

using namespace std;

// 노래 정보 
struct node {
    string tittle;
    node* next;
};

class playlist {
public:
    node* head;
    node* tail;

    playlist(int num) {
        head = new node {"", nullptr};
        tail = head; // tail이 초기에는 head와 같도록 설정

        if(num > 0) {
            for(int i = 0; i < num; i++) insert();
        }
    }

    void insert() {
        string title;
        cout << "Song tittle: ";
        getline(cin, title);

        node* new_node = new node {title, nullptr};
        tail->next = new_node;  // 새 노드를 리스트의 끝에 추가
        tail = new_node;        // tail을 새 노드를 가리키도록 업데이트
    }

    void erase() {
        node* temp = head->next;
        char check;

        cout << "Are you sure to delete latest song[y/n] ?: ";
        cin >> check;
        if(check == 'y' && temp != nullptr) {
            head->next = temp->next;
            if(temp == tail) {  // 마지막 노드를 지우는 경우
                tail = head;    // tail을 head로 되돌림
            }
            delete temp;
        }
    }

    void erase(string name) {
        node* temp = head;

        while(temp->next != nullptr && temp->next->tittle != name) {
            temp = temp->next;
        }

        if(temp->next != nullptr) {
            node* del_node = temp->next;
            temp->next = del_node->next;
            if(del_node == tail) {  // 마지막 노드를 지우는 경우
                tail = temp;        // tail을 새로운 마지막 노드로 업데이트
            }
            delete del_node;
        }
    }

    void play() {
        node* read = head->next; // 첫 노드부터 시작
        while(true) {
            if(read != nullptr && read->tittle != "") {
                cout << "Current: " <<  read->tittle << endl;
            }

            if(read->next == nullptr) { // 리스트의 끝에 도달
                cout << "You want to repeat your list[y/n]?: ";
                char check;
                cin >> check;
                if(check == 'n') {
                    cout << "Stop Playing list ... " << endl;
                    break;
                } else {
                    read = head->next; // 다시 처음부터 시작
                    continue;
                }
            }

            read = read->next;
        }
    }

    ~playlist() {
        node* temp = head;
        while(temp != nullptr) {
            node* next = temp->next;
            delete temp;
            temp = next;
        }
    }
};

int main() {
    int size;

    cout << "Enter number of songs: ";
    cin >> size;
    cin.ignore();

    playlist play(size);

    int menu = 0;
    while(menu >= 0) {
        cout << endl;
        cout << "#1. Enter new song" << endl;
        cout << "#2. Erase song on the top" << endl;
        cout << "#3. Erase song which has same tittle" << endl;
        cout << "#4. Play list " << endl;
        cout << "#5. Exit" << endl << endl;
        cout << "Enter your menu (1 ~ 5): ";
        cin >> menu;
        cin.ignore();

        if(menu == 5) break;
        else {
            switch(menu) {
                case 1:
                    play.insert();
                    break;
                case 2:
                    play.erase();
                    break;
                case 3: {
                    cout << "Erase song tittle: ";
                    string name;
                    getline(cin, name);
                    play.erase(name);
                    break;
                }
                case 4:
                    play.play();
                    break;
                default: break;
            }
        }
    }

    return 0;
}


