//
//  main.cpp
//  C++ Прорешиваем функции
//
//  Created by Павел on 08.09.2022.
//

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;


//Задача 1.Создать функцию, которая принимает любое число и выводит тип данных
void type_of(int num){
    cout<<"INT\n";
}
void type_of(char num){
cout<<"CHAR\n";
}
void type_of(double num){
cout<<"DOUBLE\n";
}
    
//Задача 2.Написать рекрсивную функцию, которая вычисляет сумму всех чисел в диапазоне от А до В
int SUM_AB (int a, int b){
  if(b==a+1)
      return a+b;
    return SUM_AB(a,b-1)+b;
}
//Задача 3. В функцию передается массив случайных чисел в диапазоне  от -20 до +20. Необходимо найти позиции крайних отрицательных элементов ( самого левого отрицательного эл. и самого правого отрицат. эл.) и отсортировать элементы, находящиеся между ними.
template <typename T> //заполнение массива случайными числами
void fill_arr(T arr[], const int length, int begin, int end){
    srand(time(0));
    for (int i=0; i<length; i++)
        arr[i] = rand()% (end-begin)+begin;
}
template <typename T>
void show_arr(T arr[], const int length){
    cout<<"[";
    for (int i=0; i<length;i++)
        cout << arr[i]<<" ";
    cout<<"]\n";
    }
//начинаем линейный поиск отрицательных элементов и сортровку элементов между ними
template <typename T>
void sort_range(T arr[],const int length){
    int first_index = 0, last_index = 0;//создаем переменные для работы с индексами элементов
    for(int i=0; i<length; i++)//идем с начала массива(первое вх)
        if(arr[i]<0){
           first_index=i;
           break;
        }
    for (int i=length-1; i>=0; i--) //идем с конца массива(последнее вх)
        if(arr[i]<0){
            last_index = i;
            break;
        }
        //пузырьковая сортировка
        for(int i = last_index-1; i>0; i--)
            for(int j = first_index+1; j < i; j++)
                if(arr[j] > arr[j+1]) {
                    swap(arr[j],arr[j+1]);
                }
        

    
}
    
    //Задача 4. Сдвиг массива. Написать функцию которая принмает массив, его длину и число. Функция сдвигает массив по кругу вправо на переданное число.(12345 -> 51234) что мы делаем: 12345->12354->12534->15234->51234
template <typename T>
void move_arr (T arr[], const int length, int moves){
    for(int j = 0; j<moves; j++){
    for(int i=length-2; i>=0;i--)//меняем предпоследний элемент с последним . Предпоследний это length-2
        swap(arr[i],arr[i+1]);
        show_arr (arr, length);
    }
    }
    

int main(int argc, const char * argv[]) {
    int n,m;

    /*
    //Задача 1.
    cout<<"15 - ";
    type_of(15);
    cout<<"\'A' - ";
    type_of('A');
    cout<<"2.5 - ";
    type_of(2.5);
    cout<<endl;
    
    
    //Задача 2.
    cout<<"Введите начало диапазона: ";
    cin>> n;
    cout<<"Введите конец диапазона: ";
    cin>> m;
    cout<<"Сумма чисел от "<< n <<" до "<< m <<" = ";
    cout<< SUM_AB(n,m);
    cout<<"\n\n";
    
*/
    //Задача 3.2
    cout<<"\nИзначальный массив : \n";
    const int size1 = 20;
    int arr1[size1];
    fill_arr(arr1,size1,-20, 20+1);
    show_arr(arr1, size1);
    cout<<"Итоговый массив: \n";
    sort_range (arr1, size1);// не сортирует!!!
    show_arr(arr1, size1);
    
    
    /*
    // Задача 4.Сдвиг массива
    const int size2 = 5;
    int arr2[size2]{1,2,3,4,5};
    show_arr(arr2,size2);
    cout<<"Введите количество сдвигов : ";
    cin>>n;
    move_arr(arr2,size2,n);
    cout<<"Итоговый массив : \n";
    show_arr(arr2,size2);
    
    */
    return 0;
}


