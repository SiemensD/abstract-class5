#include <iostream>

using namespace std;

//Базовое уравнение
class Base
{
protected:
    double a, b;

public:
    Base();
    virtual ~Base() {}
    virtual void EquationRoot() = 0;
};

Base::Base()
{
    cout << "Введите значение A = ";
    cin >> a;
    cout << "Введите значение B = ";
    cin >> b;
}

/* линейное уравнение
 * Ax + B = 0
 */
class Lineynoe : Base
{
public:
    Lineynoe();
    ~Lineynoe() {}
    void EquationRoot() override;
};

Lineynoe::Lineynoe()
{
    cout << "Уравнение имеет вид " << a << "x + " << b << " = 0" << endl;
}

void Lineynoe::EquationRoot()
{
    double x;

    x = -b / a;

    cout << "Корень уравнения равен x = " << x << endl << endl;
}

/* квадратичное уравнение
 Ax^2 + Bx + c = 0
*/
class Kvadratichnoe : Base
{
private:
    double c;

public:
    Kvadratichnoe();
    ~Kvadratichnoe() {}
    void EquationRoot() override;
};

Kvadratichnoe::Kvadratichnoe()
{
    cout << "Введите значение C = ";
    cin >> c;
    cout << "Уравнение имеет вид " << a << "x^2 + " << b << "x +" << c << " = 0" << endl;
}

void Kvadratichnoe::EquationRoot()
{
    double x1, x2;
    // определяем дискриминант
    // D=b^2-4ac
    double d = b * b - 4 * a * c;
    if (d < 0)
    {
        cout << "Koren ne soderzet deystvikelnyh chisel" << endl << endl;
        return;
    }

    if (d == 0)
    {
        x1 = x2 = -b / (2 * a);
    }
    else if (d > 0)
    {
        x1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        x2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
    }

    cout << "Корень уравнения равен x1 = " << x1 << ", x2 = " << x2 << endl << endl;
}

int main(int argc, char* argv[])
{
    setlocale(LC_ALL, "ru");

    Lineynoe lU = Lineynoe();
    lU.EquationRoot();

    Kvadratichnoe kU = Kvadratichnoe();
    kU.EquationRoot();

    return 0;
}
/*5.	Создать абстрактный базовый класс с виртуальной
функцией — корни уравнения. Создать производные
классы: класс линейных уравнений и класс квадрат-
ных уравнений. Определить функцию вычисления
корней уравнений.*/