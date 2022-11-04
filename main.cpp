
#include <iostream>
#include <vector>


struct MovieInfo {
    std::string genre;
    std::string movieName;
    std::string starActor;
    std::string parentalRating;
    double rottenTomato;
    double runTime;
    int year;

};

struct MovieGenre {
    std::vector<MovieInfo> movie;
};

/**
 *
 * @return
 */
void movieInfoStorage(MovieGenre *in);

int main() {

}

void movieInfoStorage(MovieGenre *in) {
    MovieInfo *m0 = new MovieInfo{"Mystery",
                                  "Knives Out",
                                  "Chris Evan",
                                  "PG-13",
                                  97,
                                  130};
    in->movie.push_back(*m0);
    MovieInfo *m1 = new MovieInfo{"Action",
                                  "Mission Impossible",
                                  "Tom Cruz",
                                  "PG-13",
                                  67,
                                  110,
                                  1996};
    in->movie.push_back(*m1);
    MovieInfo *m2 = new MovieInfo{"Comedy",
                                  "The Mask",
                                  "Jim Carry",
                                  "PG-13",
                                  80,
                                  100,
                                  1994};
    in->movie.push_back(*m2);
    MovieInfo *m3 = new MovieInfo{"Horror",
                                  "Conjuring",
                                  "Patrick Wilson",
                                  "Rated-R",
                                  86,
                                  110,
                                  2013};
    in->movie.push_back(*m3);

}