#include <iostream> 
#include <fstream>
using std::ios;

struct person {
    char fio[100];
    char numberOfGroup[100];
    int grades[3];
    double scholarship;
};

int main() {
    struct person ps[]{ 
        {"Sergey","SE-b-o-25-1",{5,4,5}, 2400},
        {"Robert","SE-b-o-25-1",{5,5,5}, 2400},
        {"Arthur","SE-b-o-25-1",{5,5,5}, 2400},
        {"Anton","SE-b-o-25-1",{3,4,5}, 2400},
        {"Ivan","SE-b-o-25-1",{5,4,3}, 2400},                    
    };

    //создание файла
    std::ofstream ofs("out_course.dat", ios::out | ios::binary);

    if (ofs.is_open()) {
        for (auto& p : ps)
            ofs.write((char*)&p, sizeof(p));
    }
    ofs.close();


    //чтение из файла
    struct person ps_r[5];
    int count = 0;
    std::ifstream ifs("out_course.dat", ios::in | ios::binary);

    if (ifs.is_open()) {
        while (ifs.read((char*)&ps_r[count], sizeof(person))) {
            count++;
        }
    }

    ifs.close();

    std::cout << count << std::endl;
    for (int i = 0; i < count; ++i) {
        std::cout << ps_r[i].fio << "\n";
        std::cout << ps_r[i].numberOfGroup << " " << ps_r[i].grades << " " << ps_r[i].scholarship <<
            std::endl;
    }
   
    for (int i = 0; i < count; ++i) {
        if (ps_r[i].grades[0] == 5 && ps_r[i].grades[1] == 5 && ps_r[i].grades[2] == 5) {
            ps_r[i].scholarship *= 1.5;   
        }
    }

    
    {
        std::ofstream ofs("out_course.dat", ios::out | ios::binary | ios::trunc);
        if (ofs.is_open())
            for (int i = 0; i < count; ++i)
                ofs.write((char*)&ps_r[i], sizeof(person));
    }

    
}