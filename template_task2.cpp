/*
 *  Напишите шаблонный класс Deque, содержащий следующий набор методов:
 *
    конструктор по умолчанию;
    константный метод Empty, возвращающий true, если дек не содержит ни одного элемента;
    константный метод Size, возвращающий количество элементов в деке;
    T& operator[](size_t index) и const T& operator[](size_t index) const;
    константный и неконстантный метод At(size_t index), генерирующий стандартное
    исключение out_of_range, если индекс больше или равен количеству элементов в деке;
    константные и неконстантные версии методов Front и Back, возвращающих ссылки на первый
    и последний элемент дека соответственно; методы PushFront и PushBack.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <exception>

using namespace std;

template <class T>
class Deque
{
public:

   Deque(){}                                          //-конструктор по умолчанию, т.е. без параметров;


    bool Empty() const                                //константный метод Empty, т.е. он не может менять члены  класса Deque;
    {
        return item.empty();                          //возвращает true, если дек не содержит ни одного элемента;
    }


    size_t Size() const                               //константный метод Size, // без const версии метода была бы ошибка компиляции;
    {
        return item.size();                           //возвращает количество элементов в деке;
    }


    const void At(size_t index) const                   //константный метод даёт возможность защитить значение переменной от изменений;
    {
        if (index >= item.size())                       //генерит стандартное исключение out_of_range,
            throw out_of_range("Oops! Range error\n");  //если индекс больше или равен количеству элементов в деке;
    }


    void At(size_t index)                                //неконстантный метод
    {
        if (index >= item.size())                        //генерит стандартное исключение out_of_range,
            throw out_of_range("Oops! Range error\n");   //если индекс больше или равен количеству элементов в деке;
    }


    const T& operator[](size_t index) const
    {
        if (index < this->Size())  return item[index];
        else this->At(index);
    }

    T& operator[](size_t index)
    {
        if (index < this->Size()) return item[index];
        else this->At(index);
    }

    const T &Front() const                                    //константные методы Front и Back, возвращают ссылки на первый
    {                                                         //и последний элемент дека соответственно;
        return item.front();
    }

    const T &Back() const
    {
        return item.back();
    }

    T &Front()                                                 //неконстантные методы Front и Back, возвращают ссылки на первый
    {                                                          //и последний элемент дека соответственно;
        return item.front();
    }

    T &Back()
    {
        return item.back();
    }

    void PushFront(T const& value)                               //метод PushFront - метод, который будет выдвигать элемент в начало списка;
    {
       item.insert(item.begin(), value);
    }

    void PushBack(T const& value)                                //метод PushBack - вставляет элемент в конец деки;
    {
       item.push_back(value);
    }

private:
   vector<T> item;
};

int main ()
{
              //Блок try содержит защищенный код, который может вызвать исключение.
   try        //Этот блок выполняется, пока не возникнет исключение или пока он не будет успешно завершен.
      {
        Deque <int> d;
        cout << "Empty: " << d.Empty() << endl;
        cout << "Всего элементов в деке:" << d.Size() << endl;



        cout << "Добавим по два элемента в начало и конец деки:" << endl;
        d.PushBack(33);
        d.PushBack(44);
        d.PushFront(22);
        d.PushFront(11);
        cout << "d[0]=" << d[0] << endl;
        cout << "d[1]=" << d[1] << endl;
        cout << "d[2]=" << d[2] << endl;
        cout << "d[3]=" << d[3] << endl;
        cout << "Всего элементов в деке:" << d.Size() << endl;
        cout << "Empty: " << d.Empty() << endl;


        cout << "Изменим значение последнего элемента на 12:"  << endl;
        d[3] = 12;
        cout << "d[0]=" << d[0] << endl;
        cout << "d[1]=" << d[1] << endl;
        cout << "d[2]=" << d[2] << endl;
        cout << "d[3]=" << d[3] << endl;
        cout << "d[4]=" << d[4] << endl;
        cout << "Всего элементов в деке:" << d.Size() << endl;
        cout << "Empty: " << d.Empty() << endl;
    }
    catch (out_of_range& e)// обработчик исключений
    {
        cout << "caught exception out_of_range: " << e.what() << endl;
    }

    Deque <int> d;
    d.PushBack(14);
    d.PushBack(23);
    d.PushBack(32);
    d.PushBack(41);
    cout << "d.Front(): " << d.Front() << endl;
    cout << "d.Back(): " << d.Back() << endl;
    cout << "d[0]=" << d[0] << endl;
    cout << "d[1]=" << d[1] << endl;
    cout << "d[2]=" << d[2] << endl;
    cout << "d[3]=" << d[3] << endl;

    d.Front() = 66;
    d.Back() = 99;

    cout << "d.Front(): " << d.Front() << endl;
    cout << "d.Back(): " << d.Back() << endl;
    cout << "d[0]=" << d[0] << endl;
    cout << "d[1]=" << d[1] << endl;
    cout << "d[2]=" << d[2] << endl;
    cout << "d[3]=" << d[3] << endl;

    return 0;
}



