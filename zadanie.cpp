#include <iostream>
#include <string>

class Car {
private:
    std::string model;  // Pole na model samochodu (prywatne)
    int speed;          // Pole na prêdkoœæ samochodu (prywatne)

public:
    // Konstruktor do ustawienia pocz¹tkowego modelu i prêdkoœci
    Car(std::string initModel, int initSpeed) {
        model = initModel;
        setSpeed(initSpeed);  // U¿ywamy settera aby ustawiæ prêdkoœæ
    }

    // Getter dla pola 'model' - zwraca model samochodu
    std::string getModel() const {
        return model;
    }

    // Setter dla pola 'model' - ustawia model samochodu
    void setModel(const std::string& newModel) {
        model = newModel;
    }

    // Getter dla pola 'speed' - zwraca prêdkoœæ samochodu
    int getSpeed() const {
        return speed;
    }

    // Setter dla pola 'speed' - ustawia prêdkoœæ samochodu
    void setSpeed(int newSpeed) {
        // Sprawdzamy, czy prêdkoœæ jest w prawid³owym zakresie (0-300)
        if (newSpeed >= 0 && newSpeed <= 300) {
            speed = newSpeed;
        }
        else {
            std::cout << "Prêdkoœæ nie jest prawid³owa. Ustawienie nie powiod³o siê.\n";
        }
    }

    // Funkcja zwiêkszaj¹ca prêdkoœæ samochodu
    void accelerate(int increase) {
        setSpeed(speed + increase);  // Zwiêkszamy prêdkoœæ za pomoc¹ settera
    }

    // Funkcja zmniejszaj¹ca prêdkoœæ samochodu
    void brake(int decrease) {
        setSpeed(speed - decrease);  // Zmniejszamy prêdkoœæ za pomoc¹ settera
    }
};

int main() {
    // Tworzenie obiektu klasy Car z modelem "BMW" i prêdkoœci¹ 120
    Car car("BMW", 120);

    // Wyœwietlenie informacji o samochodzie
    std::cout << "Model: " << car.getModel() << "\n";
    std::cout << "Prêdkoœæ: " << car.getSpeed() << " km/h\n";

    // Zwiêkszenie prêdkoœci o 50 km/h
    car.accelerate(50);
    std::cout << "Prêdkoœæ po przyspieszeniu: " << car.getSpeed() << " km/h\n";

    // Hamowanie o 30 km/h
    car.brake(30);
    std::cout << "Prêdkoœæ po hamowaniu: " << car.getSpeed() << " km/h\n";

    // Próba ustawienia nieprawid³owej prêdkoœci
    car.setSpeed(350);  // Powinna wyœwietliæ komunikat o b³êdzie

    return 0;
}
