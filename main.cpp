#include <iostream>
#include <functional>
#include <algorithm>
#include <iterator>
#include <random>
#include <vector>
#include <cmath>

namespace prime {

    /*!
     * \brief Функция проверяет является ли число простым.
     * \param num число для проверки.
     * \return true -- если число простое; false -- если число составное.
     */
    bool isPrime(int num)
    {
        for(int i = 2; i <= std::sqrt(num); ++i)
            if (num % i == 0) return false;

        return true;
    }

    /*!
     * \brief Функция удаления всех простых чисел из вектора.
     * \param v вектор.
     */
    template< class Vector >
    void removePrimeNumbers(Vector &v)
    {
        auto it = std::remove_if(v.begin(), v.end(), isPrime);
        v.erase(it, v.end());
        v.shrink_to_fit();
    }

    /*!
     * \brief Функция копирования всех простых чисел из одного вектора в другой.
     * \param src исходный вектор.
     * \param dst вектор назначения.
     */
    template< class Vector >
    void copyPrimeNumbers(const Vector &src, Vector &dst)
    {
        dst.clear();
        dst.reserve(src.size());
        std::copy_if(src.begin(), src.end(), std::back_inserter(dst), isPrime);
        dst.shrink_to_fit();
    }

}

int main()
{
    // Шаги по заданию 2.
    // 1. Создание вектора.
    std::vector<int> v1(100);

    // 2. Заполение вектора псевдослучайными значениями.
    std::default_random_engine gen;
    std::uniform_int_distribution<int> distr(1, 1000);
    std::generate(v1.begin(), v1.end(), std::bind(distr, gen));

    // 3. Вывод вектора.
    std::copy(v1.begin(), v1.end(), std::ostream_iterator<int>(std::cout, " "));

    // 4. Сортировка вектора.
    std::sort(v1.begin(), v1.end());

    // 5. Копирование простых числе из одного вектора в другой.
    std::vector<int> v2;
    prime::copyPrimeNumbers(v1, v2);

    // 6. Удаление простых числе из вектора.
    prime::removePrimeNumbers(v1);

    return 0;
}

