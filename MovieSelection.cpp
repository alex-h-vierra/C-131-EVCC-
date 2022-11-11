
#include <iostream>
#include <vector>
#include <iomanip>

struct Genre {
    std::string movieGenre;
};
struct MovieInfo {
    const std::string movieName;
    const std::string starActor;
    const std::string parentalRating;
    double rottenTomato = 0;
    double runTime = 0.0;
    int year = 0;
};

/**
 *
 * @return
 */
void selected_MovieInfo(MovieInfo *s);

int main() {
    MovieInfo *arrPtr[7];
    Genre *genreArrPtr[5];
    arrPtr[1] = new MovieInfo{"Knives Out",
                              "Chris Evan",
                              "PG-13",
                              67,
                              130,
                              2019};
    genreArrPtr[1] = new Genre{"Mystery"};

    arrPtr[2] = new MovieInfo{"Mission Impossible",
                              "Tom Cruz",
                              "PG-13",
                              67,
                              110,
                              2013};
    genreArrPtr[2] = new Genre{"Action"};

    arrPtr[3] = new MovieInfo{"The Mask",
                              "Jim Carry",
                              "PG-13",
                              80,
                              100,
                              1994};
    genreArrPtr[3] = new Genre{"Comedy"};

    arrPtr[4] = new MovieInfo{"The Conjuring",
                              "Patrick Wilson",
                              "Rated-R",
                              86,
                              110,
                              2013};
    genreArrPtr[4] = new Genre{"Horror"};

    std::cout << std::setw(15) << " | " << "Hello, and welcome to Black Box Movies" << " | " << std::endl;
    std::cout << std::setw(8) << " | " << "Please enter 1 to start looking for your next movie" << " | " << std::endl
              << std::endl;
    for (int i = 1; i < 5; i++) {
        std::cout << std::setw(29) << "- " << i << " " << genreArrPtr[i]->movieGenre << std::endl;
    }
    std::cout << std::setw(28) << " -" << " 0 " << "Exit" << std::endl;
    bool done = true;
    do {
        int input = 0;
        std::cin >> input;
        bool fail = std::cin.fail();
        bool isNumber = !fail;
        if (!isNumber || input < 0 || input > 4) {
            std::cout << std::setw(20) << " | " << "Oops something went wrong!" << std::endl;
            for (int i = 1; i < 5; i++) {
                std::cout << std::setw(29) << "- " << i << " " << genreArrPtr[i]->movieGenre << std::endl;
            }
            std::cout << std::setw(28) << " -" << " 0 " << "Exit" << std::endl;
            std::cin.clear();
            std::cin.ignore(100, '\n');
            done = true;
        } else if (input == 0) {
            done = false;
        } else {
            bool back = true;
            while (back) {
                std::cout << std::setw(29) << " | " << arrPtr[input]->movieName << std::endl;
                std::cout << std::setw(29) << " | " << arrPtr[input]->starActor << std::endl;
                std::cout << std::setw(28) << " -" << " 1 View " << std::endl;
                std::cout << std::setw(28) << " -" << " 0 Back " << std::endl;

                int input1 = 0;
                std::cin >> input1;
                bool fail1 = std::cin.fail();
                bool isNumber1 = !fail1;
                if (!isNumber1 || input1 < 0 || input1 > 1) {
                    std::cout << std::setw(20) << " | " << "Oops something went wrong!" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(100, '\n');
                    back = true;
                } else if (input1 == 0) {
                    std::cout << std::setw(15) << " | " << "Hello, and welcome to Black Box Movies" << " | "
                              << std::endl;
                    std::cout << std::setw(8) << " | " << "Please enter 1 to start looking for your next movie" << " | "
                              << std::endl
                              << std::endl;
                    for (int i = 1; i < 5; i++) {
                        std::cout << std::setw(29) << "- " << i << " " << genreArrPtr[i]->movieGenre << std::endl;
                    }
                    std::cout << std::setw(28) << " -" << " 0 " << "Exit" << std::endl;
                    back = false;
                } else {
                    selected_MovieInfo(arrPtr[input]);
                    back = false;
                    std::cout << std::setw(22) << " | " << "Please Select a new genre" << std::endl;
                    for (int i = 1; i < 5; i++) {
                        std::cout << std::setw(29) << "- " << i << " " << genreArrPtr[i]->movieGenre << std::endl;
                    }
                    std::cout << std::setw(28) << " -" << " 0 " << "Exit" << std::endl;
                    if ( input == 0) {
                        back = false;
                        done = false;
                    }
                }
            }
        }
    } while (done);
    for (int i = 1; i < 4; i++)
    {
        delete arrPtr[i];
    }
    for (int i = 1; i < 4; i++)
    {
        delete genreArrPtr[i];
    }
    std::cout << " Thank you come again ";
}

void selected_MovieInfo(MovieInfo *s)
{
    std::cout << std::setw(25) << " | " << s->movieName << " | " << std::endl;
    std::cout << std::setw(29) << "- " << s->starActor << std::endl;
    std::cout << std::setw(29) << "- " << s->year << std::endl;
    std::cout << std::setw(29) << "- " << s->parentalRating << std::endl;
    std::cout << std::setw(29) << "- " << s->rottenTomato << std::endl;
    std::cout << std::setw(29) << "- " << s->runTime << std::endl;
}
















