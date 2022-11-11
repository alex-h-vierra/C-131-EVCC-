/**
 * This program will be able to have the user find a particular movie
 * and view the actors, title, and year the movie was made and looped
 * back until the user is done searching a movie.
 * Preconditons -Take user input for a movie with a overly of what movies are in, and year
 * , - -view actors of that movie.
 *
 * @author Alex Vierra
 * @version Lab3 11/3/2022
 */
#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;
struct Genre
{
    string genre;
};
struct Movie
{
    string movieName;
    string starActorName;
    string parentalRating;
    int criticsRating;
    int year;
    int movieRunTime;

};

struct MovieGenre
{
    vector<Genre> movieGenre;
    vector<Movie> movieType;
};

int inputCheck(MovieGenre *arrPtr, int userInput);
void printSelectedGenre(const MovieGenre *s, int input);
void printMovieInfo(const MovieGenre *s, int input);

int main()
{
    MovieGenre arrPtr[6];
    Movie *movie;
    Genre *gMovie;
    Genre *g0 = new Genre{"Action"};
    arrPtr[1].movieGenre.push_back(*g0);
    Movie m0 = {"Mission Impossible 1",
                "Tom Cruz",
                "PG-13",
                67,
                1996,
                110};
    arrPtr[1].movieType.push_back(m0);
    arrPtr[1].movieType.push_back({"Logan",
                                   "Hugh Jackman",
                                   "Rated-R",
                                   94,
                                   2017,
                                   137});
    Genre *g1 = new Genre{"Comedy"};
    arrPtr[1].movieGenre.push_back(*g1);
    Movie m1 = {"The Mask",
                "Jim Carry",
                "PG-13",
                80,
                1994,
                100};
    arrPtr[2].movieType.push_back(m1);
    arrPtr[2].movieType.push_back({"Step-Brothers"});
    Genre *g2 = new Genre{"Horror"};
    arrPtr[1].movieGenre.push_back(*g2);
    Movie m2 = {"Conjuring",
                "Patrick Wilson",
                "Rated-R",
                86,
                2013,
                110};
    arrPtr[3].movieType.push_back(m2);
    arrPtr[3].movieType.push_back({"The Ring"});
    Genre *g3 = new Genre{"Mystery"};
    arrPtr[1].movieGenre.push_back(*g3);
    Movie m3 = {"Knives Out",
                "Chris Evan",
                "PG-13",
                97,
                2019,
                130};
    arrPtr[4].movieType.push_back(m3);
    arrPtr[4].movieType.push_back({"Sherlock Holmes"});
    bool done;
    char exit;
    do
    {
        done = true;
        for (int i = 0; i < arrPtr[0].movieType.size(); i++)
        {

        }
        cout << "\t\t\t\t\tWelcome to the Out Of Box Office movies" << endl;
        cout << "\t\t\t\t\t\t\tTo start pick a genre" << endl;
        for (int j = 0; j < 1; j++)
        {
            cout << setw(9);
            for (int i = 0; i < arrPtr[1].movieGenre.size(); i++)
            {
                cout << " | " << (i + 1) << " | " << arrPtr[1].movieGenre.at(i).genre
                     << " | ";
            }
            cout << endl;
        }
        int input = inputCheck(arrPtr, input);
        printSelectedGenre(arrPtr, input);
        cout << "Would you like to Quit (Y/N)" << endl;
        cin >> exit;
        if (toupper(exit) == 'Y')
        {
            done = false;
        }
        else if (toupper(exit) == 'N')
        {
            cin.clear();
            cin.ignore(100, '\n');
        }

    }
    while (done);

}

int inputCheck(MovieGenre *arrPtr, int userInput)
{
    bool garbage = true;
    do
    {
        cin >> userInput;
        bool fail = cin.fail();
        bool isNumber = !fail;
        if (!isNumber || userInput < 1 || userInput > arrPtr[1].movieGenre.size())
        {
            garbage = true;
            cin.clear();
            cin.ignore(100, '\n');
            cout << "\t\t\t Oops... looks like we couldn't find what you want " << endl;
            cout << setw(9);
            for (int i = 0; i < arrPtr[1].movieGenre.size(); i++)
            {
                cout << " | " << (i + 1) << " | " << arrPtr[1].movieGenre.at(i).genre
                     << " | ";
            }
            cout << endl;
            cout << "\t\t\t\t\t\tTo select the movie genre" << endl;
        }
        else
        {
            garbage = false;
        }
    }
    while (garbage);
    return userInput;
}

void printSelectedGenre(const MovieGenre *s, int input)
{
    cout << "\t\t\t\t\t\t\t\tPlease Pick: " << endl;
    for (int i = 0; i < s[input].movieType.size(); i++)
    {
        cout << setw(26) << " | " << (i + 1) << " | " << s[input].movieType[i].movieName
             << " | " - 1;
        cout << " | " << s[input].movieType[i].year << setw(11) << " | " - 1 << endl;
    }
    cout << setw(26) << "| " << "0" << " | " << setw(10) << "Quit" << setw(13)
         << " | " - 1 << endl;
    printMovieInfo(s, input);

}

void printMovieInfo(const MovieGenre *s, int input)
{
    int input1;
    cin >> input1;
    if (input1 == 0)
    {
        return;
    }
    if (input1 == 1)
    {
        cout << setw(28) << " | " << s[input].movieType[0].movieName << " | " << endl;
        cout << setw(35) << " - " << "Star Actor" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[0].starActorName << endl;
        cout << setw(35) << " - " << "Rotten Tomato" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[0].criticsRating << "%" << endl;
        cout << setw(35) << " - " << "Audience Rating" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[0].parentalRating << endl;
        cout << setw(35) << " - " << "RunTime" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[0].movieRunTime / 60 << " hrs "
             << endl;
    }
    if (input1 == 2)
    {
        cout << setw(28) << " | " << s[input].movieType[1].movieName << " | " << endl;
        cout << setw(35) << " - " << "Star Actor" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[1].starActorName << endl;
        cout << setw(35) << " - " << "Rotten Tomato" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[1].criticsRating << "%" << endl;
        cout << setw(35) << " - " << "Audience Rating" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[1].parentalRating << endl;
        cout << setw(35) << " - " << "RunTime" << " - " << endl;
        cout << setw(28) << " | " << s[input].movieType[1].movieRunTime / 60 << " hrs "
             << endl;
    }
}