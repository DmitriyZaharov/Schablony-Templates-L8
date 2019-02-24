/*Реализуйте шаблонную функцию Sqr, которая работает не только для чисел, но и для контейнеров.
 *  Функция должна возвращать копию исходного контейнера, модифицировав его следующим образом:
 *   • для vector элементы нужно возвести в квадрат;
 *   • для map в квадрат нужно возвести только значения, но не ключи;
 *   • для pair в квадрат нужно возвести каждый элемент пары.
*/

#include <iostream>
#include <vector>
#include <map>

using namespace std;

/*Int*/
template <typename T>
T Sqr(T & x)
{
    return x * x;
}

/*Vector*/
template <typename T>
vector <T> Sqr(vector<T> &c)
{
    for(auto &b : c)
    {
        b = Sqr(b);
    }
    return c;
}

/*Pair*/
template <typename T>
pair <T, T> Sqr(pair<T, T> &d)
{
    d.first *= d.first;
    d.second *= d.second;
    return d;
}

/*Map*/
template <typename T>
map <int, T> Sqr(map <int, T> &m)
{
    for (auto& n : m)
    {
        n.second = Sqr(n.second);
    }
    return m;
}

int main ()
{
 // Пример вызова функции:

 /*vector*/
    vector<int> v = {1, 2, 3};
    cout << "vector:";
    for (int x : Sqr(v))
    {
      cout << ' ' << x;
    }
    cout << endl << endl;

 /*pair*/
    pair<int, int> pr = {3, 4};
    cout << "pairs:" << endl;
    cout << "{" << pr.first << ", " << pr.second << "}" << endl;
    pr = Sqr(pr);
    cout << "Sqr pairs:" << endl;
    cout << "{" << pr.first << ", " << pr.second << "}" << endl << endl;

/*map*/
    map<int, pair<int, int>> map_of_pairs =
    {
      {4, {2, 2}},
      {7, {4, 3}}
    };

    cout << "map of pairs:" << endl;
    for (const auto& x : Sqr(map_of_pairs))
    {
      cout << x.first << ' ' << x.second.first << ' ' << x.second.second << endl;
    }

    return 0;
}
