#include "IO/FillMatrix.hpp"

#include <fstream>
#include <iostream>
#include <map>
#include <set>

using namespace std;

struct Position
{
    int row, col;

    Position() :
        row(),
        col()
    {
    }

    Position(int row, int col) :
        row(row),
        col(col)
    {
    }
};

struct PositionComparer
{
    bool operator()(const Position & p1, const Position & p2)
    {
        if(p1.row < p2.row)
            return true;
        else if(p1.row > p2.row)
            return false;
        else if(p1.col < p2.col)
            return true;
        else
            return false;
    }
};

template<int N>
struct WormComparer;

template<int N>
class Worm
{
    Position p;
    long long value;

    typedef long long (*MatrixType)[N];

    map<Position, Worm<N>, PositionComparer> * wormsPosition;
    set<Worm<N>, WormComparer<N> > * rankedWorms;
    MatrixType matrix;

    public :

    Worm() :
        p(),
        value(),
        wormsPosition(),
        rankedWorms(),
        matrix()
    {
    }

    Worm(Position p, long long value, map<Position, Worm<N>, PositionComparer > * wormsPos, set<Worm<N>, WormComparer<N> > * rankedWorms, MatrixType matrix) :
        p(p),
        value(value),
        wormsPosition(wormsPos),
        rankedWorms(rankedWorms),
        matrix(matrix)
    {
    }

    Position GetPosition() const
    {
        return p;
    }

    long long GetValue() const
    {
        return value;
    }

    bool CanExpand() const
    {
        if(p.row > 0 &&
           (wormsPosition->find(Position(p.row - 1, p.col)) == wormsPosition->end() ||
            wormsPosition->find(Position(p.row - 1, p.col))->second.value > this->value + ((MatrixType)matrix)[p.row - 1][p.col] ) )
        {
            return true;
        }

        if(p.row < N - 1 &&
           (wormsPosition->find(Position(p.row + 1, p.col)) == wormsPosition->end() ||
            wormsPosition->find(Position(p.row + 1, p.col))->second.value > this->value + ((MatrixType)matrix)[p.row + 1][p.col] ) )
        {
            return true;
        }

        if(p.col < N - 1 &&
           (wormsPosition->find(Position(p.row, p.col + 1)) == wormsPosition->end() ||
            wormsPosition->find(Position(p.row, p.col + 1))->second.value > this->value + ((MatrixType)matrix)[p.row][p.col + 1] ) )
        {
            return true;
        }

        return false;
    }

    void Expand() const
    {
        if(p.row > 0)
        {
            Position pNext(p.row - 1, p.col);
            Worm wNext(pNext, this->value + matrix[p.row - 1][p.col], wormsPosition, rankedWorms, matrix);

            if(wormsPosition->find(Position(p.row - 1, p.col)) == wormsPosition->end())
            {
                (*wormsPosition)[pNext] = wNext;
                rankedWorms->erase(wNext);
                rankedWorms->insert(wNext);
            }
            else if(wormsPosition->find(Position(p.row - 1, p.col))->second.value > wNext.value)
            {
                (*wormsPosition)[pNext] = wNext;
                rankedWorms->erase(wNext);
                rankedWorms->insert(wNext);
            }
        }

        if(p.row < N - 1)
        {
            Position pNext(p.row + 1, p.col);
            Worm wNext(pNext, this->value + matrix[p.row + 1][p.col], wormsPosition, rankedWorms, matrix);

            if(wormsPosition->find(Position(p.row + 1, p.col)) == wormsPosition->end())
            {
                (*wormsPosition)[pNext] = wNext;
                rankedWorms->erase(wNext);
                rankedWorms->insert(wNext);
            }
            else if(wormsPosition->find(Position(p.row + 1, p.col))->second.value > wNext.value)
            {
                (*wormsPosition)[pNext] = wNext;
                rankedWorms->erase(wNext);
                rankedWorms->insert(wNext);
            }
        }

        if(p.col < N - 1)
        {
            Position pNext(p.row, p.col + 1);
            Worm wNext(pNext, this->value + matrix[p.row][p.col + 1], wormsPosition, rankedWorms, matrix);

            if(wormsPosition->find(Position(p.row, p.col + 1)) == wormsPosition->end())
            {
                (*wormsPosition)[pNext] = wNext;
                rankedWorms->erase(wNext);
                rankedWorms->insert(wNext);
            }
            else if(wormsPosition->find(Position(p.row, p.col + 1))->second.value > wNext.value)
            {
                (*wormsPosition)[pNext] = wNext;
                rankedWorms->erase(wNext);
                rankedWorms->insert(wNext);
            }
        }
    }
};

template<int N>
struct WormComparer
{
    bool operator()(const Worm<N> & w1, const Worm<N> & w2)
    {
        if(w1.CanExpand() && !w2.CanExpand())
            return true;
        else if(!w1.CanExpand() && w2.CanExpand())
            return false;
        else if(w1.GetValue() < w2.GetValue())
            return true;
        else if(w1.GetValue() > w2.GetValue())
            return false;

        PositionComparer comparer;
        return comparer(w1.GetPosition(), w2.GetPosition());
    }
};

int main()
{
    ifstream f("matrix.txt");
    string str((istreambuf_iterator<char>(f)),
                 istreambuf_iterator<char>());

    f.close();

#define MATRIX_SIZE 80

    long long mat[MATRIX_SIZE][MATRIX_SIZE];

    FillMatrix(mat, str);

    map<Position, Worm<MATRIX_SIZE>, PositionComparer> wormsPosition;
    set<Worm<MATRIX_SIZE>, WormComparer<MATRIX_SIZE> > rankedWorms;

    for(int i = 0 ; i < MATRIX_SIZE ; ++i)
    {
        //Position p, long long value, map<Position, Worm<N> > * wormsPos, set<Worm<N>, WormComparer<N> > * rankedWorms, void * matrix
        Worm<MATRIX_SIZE> w(Position(i,0), mat[i][0], &wormsPosition, &rankedWorms, mat);

        wormsPosition[w.GetPosition()] = w;
        rankedWorms.insert(w);
    }

    long long minVal = 0x7fffffffffffffffLL;

    while(true)
    {
        Worm<MATRIX_SIZE> w = *rankedWorms.begin();
        rankedWorms.erase(rankedWorms.begin());

        if(w.GetPosition().col == MATRIX_SIZE - 1)
            if(minVal > w.GetValue())
                cout << endl << (minVal = w.GetValue()) << " " << w.CanExpand() << endl;

        w.Expand();
        rankedWorms.insert(w);
    }

    return 0;
}
