#include <iostream>
#include <string>

class Car {
private:
    std::string model;  // Pole na model samochodu (prywatne)
    int speed;          // Pole na pr�dko�� samochodu (prywatne)

public:
    // Konstruktor do ustawienia pocz�tkowego modelu i pr�dko�ci
    Car(std::string initModel, int initSpeed) {
        model = initModel;
        setSpeed(initSpeed);  // U�ywamy settera aby ustawi� pr�dko��
    }

    // Getter dla pola 'model' - zwraca model samochodu
    std::string getModel() const {
        return model;
    }

    // Setter dla pola 'model' - ustawia model samochodu
    void setModel(const std::string& newModel) {
        model = newModel;
    }

    // Getter dla pola 'speed' - zwraca pr�dko�� samochodu
    int getSpeed() const {
        return speed;
    }

    // Setter dla pola 'speed' - ustawia pr�dko�� samochodu
    void setSpeed(int newSpeed) {
        // Sprawdzamy, czy pr�dko�� jest w prawid�owym zakresie (0-300)
        if (newSpeed >= 0 && newSpeed <= 300) {
            speed = newSpeed;
        }
        else {
            std::cout << "Pr�dko�� nie jest prawid�owa. Ustawienie nie powiod�o si�.\n";
        }
    }

    // Funkcja zwi�kszaj�ca pr�dko�� samochodu
    void accelerate(int increase) {
        setSpeed(speed + increase);  // Zwi�kszamy pr�dko�� za pomoc� settera
    }

    // Funkcja zmniejszaj�ca pr�dko�� samochodu
    void brake(int decrease) {
        setSpeed(speed - decrease);  // Zmniejszamy pr�dko�� za pomoc� settera
    }
};

int main() {
    // Tworzenie obiektu klasy Car z modelem "BMW" i pr�dko�ci� 120
    Car car("BMW", 120);

    // Wy�wietlenie informacji o samochodzie
    std::cout << "Model: " << car.getModel() << "\n";
    std::cout << "Pr�dko��: " << car.getSpeed() << " km/h\n";

    // Zwi�kszenie pr�dko�ci o 50 km/h
    car.accelerate(50);
    std::cout << "Pr�dko�� po przyspieszeniu: " << car.getSpeed() << " km/h\n";

    // Hamowanie o 30 km/h
    car.brake(30);
    std::cout << "Pr�dko�� po hamowaniu: " << car.getSpeed() << " km/h\n";

    // Pr�ba ustawienia nieprawid�owej pr�dko�ci
    car.setSpeed(350);  // Powinna wy�wietli� komunikat o b��dzie

    return 0;
}
