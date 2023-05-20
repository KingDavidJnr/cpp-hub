#include <iostream>
#include <string>
#include <vector>

// Class representing a movie
class Movie {
private:
    std::string title;
    std::string director;
    int releaseYear;

public:
    // Constructor
    Movie(const std::string& _title, const std::string& _director, int _releaseYear)
        : title(_title), director(_director), releaseYear(_releaseYear) {
    }

    // Method to get the movie title
    std::string getTitle() const {
        return title;
    }

    // Method to get the movie director
    std::string getDirector() const {
        return director;
    }

    // Method to get the movie release year
    int getReleaseYear() const {
        return releaseYear;
    }
};

// Class representing a movie streaming app
class MovieStreamingApp {
private:
    std::vector<Movie> movies;

public:
    // Method to add a movie to the app
    void addMovie(const Movie& movie) {
        movies.push_back(movie);
    }

    // Method to display all movies in the app
    void displayMovies() const {
        std::cout << "Movies in the streaming app:" << std::endl;
        for (const Movie& movie : movies) {
            std::cout << "Title: " << movie.getTitle() << std::endl;
            std::cout << "Director: " << movie.getDirector() << std::endl;
            std::cout << "Release Year: " << movie.getReleaseYear() << std::endl;
            std::cout << std::endl;
        }
    }
};

int main() {
    // Create an instance of the movie streaming app
    MovieStreamingApp app;

    // Add some movies to the app
    Movie movie1("Inception", "Christopher Nolan", 2010);
    app.addMovie(movie1);

    Movie movie2("The Shawshank Redemption", "Frank Darabont", 1994);
    app.addMovie(movie2);

    Movie movie3("Pulp Fiction", "Quentin Tarantino", 1994);
    app.addMovie(movie3);

    // Display all movies in the app
    app.displayMovies();

    return 0;
}
