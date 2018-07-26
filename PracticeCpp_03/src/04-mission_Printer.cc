// /*
//     Copyright 2018 Moreal
// */

// #include <iostream>
// #include <string>


// class Printer {
//     std::string model, manufacturer;
//     int printedCount, availableCount;

//  public:
//     Printer(const std::string&, const std::string&, const int, const int);

//     virtual bool print(const int);
//     virtual void show();
// };

// class InkPrinter : public Printer {
//     int availableInk;

//  public:
//     InkPrinter(const std::string&, const std::string&, const int, const int);
    
//     bool print(const int) override;
//     void show() override;
// };

// class LaserPrinter : public Printer {
//     int availableToner;
//  public:
//     Laze rPrinter(const std::string&, const std::string&, const int, const int);

//     bool print(const int) override;
//     void show() override;
// };

// bool Printer::print(const int pages) {
//     if (pages <= availableCount) {
//         availableCount -= pages;
//         printedCount += pages;
//         std::puts("[!] Printed!!");
//         return true;
//     }

//     std::puts("[!] There aren't pages enough");
//     return false;
// }

// void Printer::show() {
//     std::cout
//         << model << ','
//         << manufacturer << ','
//         << " remained paper count is " << availableCount;
// }

// void InkPrinter::show() {
//     Printer::show();
//     std::cout << ", remained ink is " << availableInk << '\n';
// }

// void LaserPrinter::show() {
//     Printer::show();
//     std::cout << ", remained toner is " << availableToner << '\n';
// }

// bool InkPrinter::print(const int pages) {
//     if (Printer::print(pages))
//         availableInk -= pages;
// }

// bool LaserPrinter::print(const int pages) {
//     if (Printer::print(pages))
//         availableToner -= pages;
// }


// int main() {
//     Printer printers[] = {new InkPrinter()}
//     return 0;
// }