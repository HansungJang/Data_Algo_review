// #  Goal: '동적 크기 배열' 구현 (동적 메모리 함수)

// keywords: 깊은/얕은 복사, operator를 사용한 wrapper class구현

// 새롭게 알게된 문법:
// 1. sstream(ostringstram / 다양한 타입을 문자열로 변환 저장),
// 2. friend (private, protected 멤버를 접근할 수 있음),
// 3. ' ... '의 의미  (try-catch문에서 모든 예외를 처리)


// input: 학생수, 학생 정보 
// design: 배열 
// function: 다양한 크기 배열, 여러반을 하나로 합치는 기능

#include <iostream>
#include <sstream> // string type 입력 
#include <algorithm>
#include <string>

using namespace std; 


template <typename T> // 임의의 숫자 
class dynamic_array
{
    T* data; 
    size_t n;

    //배열 크기를 인자로 받는 생성자
    public: 
        dynamic_array(int n)
        {
            this->n = n; 
            this->data = new T[n]; 
        }


    //복사 생성자
        dynamic_array(const dynamic_array<T>& other)
        {
            this->n = other.n;
            this->data = new T[n]; 
            
            // int i = 0; 
            // for(T elem : other.data)
            // {
            //     this.data[i++] = elem; 
            // }

            for(int i = 0; i < n; i++)
            {
                data[i] = other[i];
            } 
        }  


        // member 변수에 접근 하는 함수 
        T& operator[](int index) // 원본 수정가능 read, write (O)
        {
            return data[index]; 
        }

        const T& operator[](int index) const // only read 
        {
            return data[index]; 
        }

        T& at(int index) // java style 
        {
            if(index < n)
                return data[index]; 
            throw "Index is out of range"; 
        }

        size_t size() const 
        {
            return n; 
        }

        // 반복자 순회에 사용될 반복자 관련 함수 
        T* begin() {return data;}
        const T* begin() const {return data;}
        T* end() {return data + n;}
        const T* end() const {return data + n;}

        // 두 반을 하나로 합치는 함수 
        friend dynamic_array<T> operator+(const dynamic_array<T>& arr1, dynamic_array<T>& arr2)
        {
            dynamic_array<T> result(arr1.size() +  arr2.size());
            copy(arr1.begin(), arr1.end(), result.begin());
            copy(arr2.begin(), arr2.end(), result.begin() + arr1.size());

            return result;  
        }

        // 문자열 구분 
        string to_string(const string& sep = ", ")
        {
            if(n == 0) return ""; 

            ostringstream os; 
            // for(T elem : data)
            for(int i = 0; i < n; i++)
            {
                os << data[i]; 
                if(i < (n-1)) os << sep; 
                
            } 

            return os.str(); 

        }


        ~dynamic_array()
        {
            delete[] data; 
        }

}; 


struct student
{
    string name; 
    int age;  
}; 

ostream& operator<<(ostream& os, const student& s)
{
    return (os<< "[" << s.name << "," << s.age << "]"); 
}

int main()
{
    int nStudents; 
    cout << "1st class student number : "; 
    cin >> nStudents; 
    dynamic_array<student> class1(nStudents);
    for(int i = 0; i < nStudents; i++)
    {
     //   std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');


        string name; 
        int age; 
        cin.ignore();

        cout << (i+1) << "th stdent name : "; 
        getline(cin, name); 
        cout << (i+1) << "th stdent age : "; 
        cin >> age;  

        class1[i] = student{name, age}; 
    }

// 예외 발생 조건 
    try
    {
        class1.at(nStudents) = student{"John", 8}; 
    }catch(...)
    {
        cout << "exception throw!" << endl; 
    }

// 깊은 복사 (only value)

    cout << "깊은 복사 " <<  endl;  
    auto class2 = class1; 

    cout << "1반을 복사하여 2반 생성" << endl;
    cout << "1반 정보 : " << class1.to_string() << endl; 
    cout << "2반 정보 : " << class2.to_string() << endl;

    class2[0].age = 99; 

    cout << "1반 정보 : " << class1.to_string() << endl; 
    cout << "2반 정보 : " << class2.to_string() << endl;

    cout << endl; 

// 얕은 복사 
    cout << "얕은 복사 " << endl;  
    auto* class3 = &class1;

    cout << "1반을 복사하여 3반 생성" << endl;
    cout << "1반 정보 : " << class1.to_string() << endl; 
    cout << "3반 정보 : " << class2.to_string() << endl;

    (class3->begin()->age) = 98; 

    cout << "1반 정보 : " << class1.to_string() << endl; 
    cout << "3반 정보 : " << (*class3).to_string() << endl;


    cout << endl; 

//  두 학급을 합치는 연산 
    auto class4 = class1 + class2; 
    cout << "1, 2반을 합쳐 4반 생성 : " << class4.to_string() << endl; 

}