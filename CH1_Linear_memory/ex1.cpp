// vector 구현 (동적 메모리 함수)
// input: 학생수, 학생 정보 
// design: 배열 
// function: 다양한 크기 배열, 여러반을 하나로 합치는 기능

#include <iostream>
#include <sstream> // string type 입력 
#include <algorithm>

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
            
            int i = 0; 
            for(T elem : other.data)
            {
                this.data[i++] = elem; 
            } 
        }  


        // member 변수에 접근 하는 함수 
        T& operator[](int index) // 원본 수정가능 read, write (O)
        {
            return this.data[index]; 
        }

        const T& operator[](int index) const // only read 
        {
            return this.data[index]; 
        }

        T& at(int index) // java style 
        {
            if(index < n)
                return this->data[index]; 
            throw "Index is out of range"; 
        }

        size_t size() const 
        {
            return this.n; 
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
            copy(arr1.begin(), arr1.end(), data.begin());
            copy(arr2.begin(), arr2.end(), data.begin() + arr1.size());

            return data;  
        }



        ~dynamic_array()
        {
            delete[] data; 
        }

}; 

