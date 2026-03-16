#include <iostream>
using namespace std;

class Media {
protected:
    string title;
    string pubDate;
    int    uid;
    string publisher;
    bool   checkedOut;

public:
    Media(string t, string date, int id, string pub)
    {
        title      = t;
        pubDate    = date;
        uid        = id;
        publisher  = pub;
        checkedOut = false;
    }

    virtual void displayInfo()
    {
        cout << "Title     : " << title     << endl;
        cout << "Pub Date  : " << pubDate   << endl;
        cout << "ID        : " << uid       << endl;
        cout << "Publisher : " << publisher << endl;
    }

    void checkOut()
    {
        if (!checkedOut)
        {
            checkedOut = true;
            cout << title << " has been checked out." << endl;
        }
        else
            cout << "Item already checked out." << endl;
    }

    void returnItem()
    {
        if (checkedOut)
        {
            checkedOut = false;
            cout << title << " has been returned." << endl;
        }
        else
            cout << "Item was not checked out." << endl;
    }

    string getTitle()   { return title;  }
    string getPubDate() { return pubDate; }
};


class Book : public Media {
private:
    string author;
    string isbn;
    int    pages;

public:
    Book(string t, string date, int id, string pub,
         string a, string i, int p)
        : Media(t, date, id, pub)
    {
        author = a;
        isbn   = i;
        pages  = p;
    }

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Author : " << author << endl;
        cout << "ISBN   : " << isbn   << endl;
        cout << "Pages  : " << pages  << endl;
    }

    string getAuthor() { return author; }
};


class DVD : public Media {
private:
    string director;
    int    duration;
    string rating;

public:
    DVD(string t, string date, int id, string pub,
        string dir, int dur, string rate)
        : Media(t, date, id, pub)
    {
        director = dir;
        duration = dur;
        rating   = rate;
    }

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Director : " << director          << endl;
        cout << "Duration : " << duration << " min" << endl;
        cout << "Rating   : " << rating             << endl;
    }
};


class CD : public Media {
private:
    string artist;
    int    tracks;
    string genre;

public:
    CD(string t, string date, int id, string pub,
       string a, int tr, string g)
        : Media(t, date, id, pub)
    {
        artist = a;
        tracks = tr;
        genre  = g;
    }

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Artist : " << artist << endl;
        cout << "Tracks : " << tracks << endl;
        cout << "Genre  : " << genre  << endl;
    }
};


class Magazine : public Media {
private:
    int issueNo;

public:
    Magazine(string t, string date, int id, string pub, int issue)
        : Media(t, date, id, pub)
    {
        issueNo = issue;
    }

    void displayInfo() override
    {
        Media::displayInfo();
        cout << "Issue No : " << issueNo << endl;
    }
};


class Library {
private:
    Media* items[50];
    int    count;

public:
    Library() { count = 0; }

    void addMedia(Media* m)
    {
        items[count++] = m;
    }

    void search(string title)
    {
        cout << "\n/-/-/-/-/-/- search by title /-/-/-/-/-/-" << endl;
        for (int i = 0; i < count; i++)
            if (items[i]->getTitle() == title)
                items[i]->displayInfo();
    }

    void search(string author, bool byAuthor)
    {
        cout << "\n/-/-/-/-/-/- search by author /-/-/-/-/-/-" << endl;
        for (int i = 0; i < count; i++)
        {
            Book* b = dynamic_cast<Book*>(items[i]);
            if (b && b->getAuthor() == author)
                b->displayInfo();
        }
    }

    void search(int year, bool byYear)
    {
        cout << "\n/-/-/-/-/-/- search by year /-/-/-/-/-/-" << endl;
        string yr = to_string(year);
        for (int i = 0; i < count; i++)
            if (items[i]->getPubDate() == yr)
                items[i]->displayInfo();
    }
};


int main()
{
    Library lib;

    Book     b1("C++ Programming", "2020", 101, "Pearson",
                "Bjarne Stroustrup", "12345", 800);
    DVD      d1("Inception",        "2010", 201, "Warner Bros",
                "Christopher Nolan", 148, "PG-13");
    CD       c1("Thriller",         "1982", 301, "Sony",
                "Michael Jackson", 9, "Pop");
    Magazine m1("Tech Monthly",     "2024", 401, "TechPress", 12);

    lib.addMedia(&b1);
    lib.addMedia(&d1);
    lib.addMedia(&c1);
    lib.addMedia(&m1);

    cout << "\n/-/-/-/-/-/- book info /-/-/-/-/-/-" << endl;
    b1.displayInfo();

    cout << "\n/-/-/-/-/-/- dvd info /-/-/-/-/-/-" << endl;
    d1.displayInfo();

    cout << "\n/-/-/-/-/-/- cd info /-/-/-/-/-/-" << endl;
    c1.displayInfo();

    cout << "\n/-/-/-/-/-/- magazine info /-/-/-/-/-/-" << endl;
    m1.displayInfo();

    cout << "\n/-/-/-/-/-/- checkout and return /-/-/-/-/-/-" << endl;
    b1.checkOut();
    b1.checkOut();
    b1.returnItem();

    lib.search("C++ Programming");
    lib.search("Bjarne Stroustrup", true);
    lib.search(2010, true);

    return 0;
}
