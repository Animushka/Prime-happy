#include <iostream>
#include <string> // подключаем строки
#include <fstream> // подключаем файлы
#include <vector>
#include <set>
#include <iomanip>

/*
Есть 2 текстовых файла.
 *  В них нужно найти и удалить числа,
 *  которые дублируются.
 * Первый файл .txt содержит список всех простых чисел от 0 до 1000,
 *  а второй файл .txt содержит список всех «счастливых чисел» от 0 до 1000.
 * (Если вы забыли,
 * то простые числа — это числа, которые имеют 2 делителя:
 * единицу и самого себя,
 *  о «счастливых числах» вы можете почитать в Википедии).

 */


using namespace std; // используем стандартное пространство имен
void totext(vector <int>& vect, ofstream& txt);
void fromtext(vector <int>& vect, ifstream& txt);
void print(auto s);
void compareVect(vector <int>& vect_first, vector <int>& vect_second);


int main() {
    setlocale(LC_ALL, "Russian");
    string s; vector <int> prime_num; vector <int> happy_num; // сюда будем класть считанные строки    
    ifstream text_file_prime("D:\\prog\\prime_numbers.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
    fromtext(prime_num,text_file_prime);
    text_file_prime.close(); // обязательно закрываем файл что бы не повредить его
    ifstream text_file_happy("D:\\prog\\happy_numbers.txt"); // файл из которого читаем (для линукс путь будет выглядеть по другому)
    fromtext(happy_num ,text_file_happy);
    text_file_happy.close(); // обязательно закрываем файл что бы не повредить его
    cout << "Простые числа: " << endl;
    print(prime_num);
    cout << "Счастливые числа: " << endl;
    print(happy_num);
    compareVect(prime_num, happy_num);
    cout << "Простые числа, после удаления: " << endl;
    print(prime_num);
    cout << "Счастливые числа , после удаления: " << endl;
    print(happy_num);
    ofstream out_prime("D:\\prog\\prime_numbers_after.txt");
    ofstream out_happy("D:\\prog\\happy_numbers_after.txt");
    totext(prime_num, out_prime);
    totext(happy_num, out_happy);
    cout << "Результат находиться по пути: \n D:\\prog\\prime_numbers_after.txt \n D:\\prog\\happy_numbers_after.txt \n  \n  \n" ;
    out_prime.close();
    out_happy.close();
}

void fromtext(vector <int>& vect ,ifstream& txt)
{
    int currentNumber{0};
	while (!(txt.eof()))
	{
		txt >> currentNumber;
		vect.push_back(currentNumber);
	}
}
void totext(vector <int>& vect, ofstream& txt)
{
    int currentNumber{ 0 };
    for (int i = 0; i < vect.size(); ++i) {
        txt << vect[i] << endl;
    }
}

void print(auto s)
{
    for (auto num : s)
    {
        cout << setw(4) << num << '|';
    }
    cout << endl;
}
void compareVect(vector <int>& vect_first, vector <int>& vect_second) 
{
    set <int> repeat;
    for (int i = 0; i < max(vect_first.size(), vect_second.size()); i++)
    {
        if (std::find(vect_second.begin(), vect_second.end(), vect_first.at(i)) != vect_second.end()) {
            repeat.insert(vect_first.at(i));
        }
    }
    cout << "Повторы" << endl;
    print(repeat);
    cout << "Кол-во повторов: " << repeat.size() << endl;
    for (auto num : repeat)
    {
        for (int i = 0; i < vect_first.size(); i++)
            if (num == vect_first.at(i))
            vect_first.erase(vect_first.begin() + i);
        for (int j = 0; j < vect_second.size(); j++)
            if (num == vect_second.at(j))
            vect_second.erase(vect_second.begin() + j);
    }
}
