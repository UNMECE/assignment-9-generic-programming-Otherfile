#include<iostream>
using namespace std;

template<typename T>

class GenericArray {

  private:
    T* array;
    int array_size = 0;

  public: 
    GenericArray(){array = 0; array_size = 0;}
    ~GenericArray(){delete[] array;}


  void addElement(T element){

      T* newArray = new T[array_size + 1];
      for (int i = 0; i < array_size; i++){
        newArray[i] = array[i];
      }

    newArray[array_size] = element;

    array = newArray;

    array_size++;
  }

  T* slice(int begin, int end){


    int newSize = (end - begin) + 1;

    T* slice = new T[newSize];

    for (int i = begin ; i <= end; i++){
    
      slice[i-1] = array[i];

    } 
    
    return slice;
  }

  T at(int index){


    if (index < array_size){
      return array[index];
    } else {
      cout << "The specified index was not in the bounds of the array" << endl;
      return 0;
    }

  }

  T min(){

    T min = array[0];
    
    for (int i = 1; i < array_size; i++){

      if (min > array[i]){
        min = array[i];
    }

  }
  
    return min;
}

  T max(){

    T max = array[0];
    
    for (int i = 1; i < array_size; i++){

      if (max < array[i]){
        max = array[i];
    }

  }
  
    return max;
  }

  T sum(){

    T sum = 0;

    for (int i = 0; i < array_size; i++){

      sum += array[i];

    }
    
    return sum;

  }
  
  int size(){
    return array_size;
  }

  void print(){

    for (int i = 0; i < array_size; i++){

      cout << array[i] << " ";

    }
    cout << endl;
  }

};


int main(){

  GenericArray<int> array;
  array.addElement(10);
  array.addElement(3);
  array.addElement(7);
  array.addElement(2);
  array.addElement(4);
  array.addElement(14);
  array.addElement(6);
  array.addElement(20);
  array.addElement(17);
  array.addElement(15);
  array.addElement(12);
  array.addElement(11);
  array.addElement(5);
  array.addElement(1);

  cout << "Array before slicing: " << endl;
  cout << "Sum of Elements: " << array.sum() << endl;
  cout << "Size: " << array.size() << endl;
  cout << "Min: " << array.min() << endl;
  cout << "Max: " << array.max() << endl;
  cout << "Value at index 13: " << array.at(13) << endl;
  array.print();

  int* sliced_array = array.slice(1, 6);

  cout << "Sliced Array: ";

  for (int i = 0; i < 6; i++){

    cout << sliced_array[i] << " ";

  }

  cout << endl;

  delete[] sliced_array;

  return 0;
  
}

