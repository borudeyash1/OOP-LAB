#include <iostream>
#include <string>

class Binary {
private:
    std::string s;

public:
    void read();
    void display() const;
    bool chk_bin() const; // Check if the number is binary
    void ones_complement() const; // Calculate one's complement
};

void Binary::read() {
    std::cout << "Enter a binary number: ";
    std::cin >> s;
}

void Binary::display() const {
    std::cout << "Displaying the binary number: " << s << std::endl;
}

bool Binary::chk_bin() const {
    for (size_t i = 0; i < s.length(); i++) {
        if (s.at(i) != '0' && s.at(i) != '1') {
            return false; // Not a binary number
        }
    }
    return true; // It's a binary number
}

void Binary::ones_complement() const {
    std::string complement;
    for (char c : s) {
        complement += (c == '0') ? '1' : '0'; // Flip bits
    }
    std::cout << "One's complement: " << complement << std::endl;
}

int main() {
    Binary b;

    std::cout << "---------CHECKING IF THE NUMBER IS BINARY OR NOT------\n";

    b.read();
    b.display();

    if (b.chk_bin()) {
        std::cout << "The number is binary." << std::endl;
        b.ones_complement();
    } else {
        std::cout << "The number is not binary." << std::endl;
    }

    return 0;
}