#include <iostream>
#include <map>
#include <memory>
#include <set>
#include <sstream>
#include <vector>


void computeSolutions(std::map<int, std::map<int, int>> & table, std::map<int, std::map<int, long long>> & tableCount, int rMax, int cMax, int r, int c, int colors, long long & count)
{
    if (r == rMax)
    {
        // for (int r = 0 ; r < rMax ; ++r)
        // {
        //     for (int c = 0 ; c < cMax ; ++c)
        //     {
        //         std::cout << table[r][c] << ", ";
        //     }
        //     std::cout << std::endl;
        // }
        // std::cout << std::endl;

        count += 1;
        return;
    }

    for (int i = 0 ; i < colors ; ++i)
    {
        if (r > 0 && table[r - 1][c] == i)
            continue;

        if (c > 0 && table[r][c - 1] == i)
            continue;

        table[r][c] = i;
        ++tableCount[r][c];

        if (c == cMax - 1)
        {
            computeSolutions(table, tableCount, rMax, cMax, r + 1, 0, colors, count);
        }
        else
        {
            computeSolutions(table, tableCount, rMax, cMax, r, c + 1, colors, count);
        }
    }
}

void displayCount(int rMax, int cMax, int colors)
{
    std::map<int, std::map<int, int>> table;
    std::map<int, std::map<int, long long>> tableCount;
    long long count = 0;
    computeSolutions(table, tableCount, rMax, cMax, 0, 0, colors, count);

    for (int i = 0 ; i < rMax ; ++i)
    {
        for (int j = 0 ; j < cMax ; ++j)
        {
            std::cout << tableCount[i][j] << ", ";
        }
        std::cout << std::endl;
    }

    //std::cout << "{" << rMax << ", " << cMax << "}: " << count << std::endl;
}

struct Index
{
    int r, c;

    Index(int r, int c) :
        r(r),
        c(c)
    {
    }

    Index() :
        r(0),
        c(0)
    {
    }

    bool operator<(Index const & other) const
    {
        if (r < other.r)
            return true;
        if (other.r < r)
            return false;

        return c < other.c;
    }

    bool operator!=(Index const & other) const
    {
        return (other < *this) || (*this < other);
    }
};

std::ostream & operator<<(std::ostream & os, Index const & i)
{
    os << "{" << i.r << ", " << i.c << "}";

    return os;
}

struct Event
{
    enum EventType {
        Inter, Union, DifferenceEvent, EqualityEvent
    };

    EventType eventType;

    Event(EventType eventType) : eventType(eventType) {}
    ~Event() {}

    EventType getType() { return eventType; }
    virtual std::string dump() = 0;
    virtual void reduce() = 0;
};

struct Inter :
    public Event,
    public std::enable_shared_from_this<Inter>
{
    std::set<std::shared_ptr<Event>> children;

    Inter() : Event(Event::Inter) {}

    void reduceChildren()
    {
        auto it = children.begin();
        while (it != children.end())
        {
            if ((*it)->getType() == Event::Inter)
            {
                auto other = std::static_pointer_cast<Inter>(*it);
                for (auto child : other->children)
                {
                    children.insert(child);
                }
                it = children.erase(it);
            }

            ++it;
        }
    }

    void reduceSiblings()
    {
        auto it1 = children.begin();
        while (it1 != children.end())
        {
            auto it2 = children.begin();
            while (it2 != children.end())
            {
                if (it1 == it2)
                {
                    ++it2;
                    continue;
                }

                if ((*it1)->dump() == (*it2)->dump())
                    it2 = children.erase(it2);
                else
                    ++it2;
            }

            ++it1;
        }
    }

    virtual void reduce()
    {
        for (auto & child : children)
            child->reduce();

        reduceChildren();
        // Reducing twice is necessary
        reduceChildren();
    }

    virtual std::string dump()
    {
        std::stringstream sstream;

        auto it = children.begin();
        while (it != children.end())
        {
            sstream << "(" << (*it)->dump() << ")";
            if (++it != children.end())
                sstream << " ⋂ ";
        }

        return sstream.str();
    }

    bool operator<(Inter const & other)
    {
    }
};

struct Union :
    public Event,
    public std::enable_shared_from_this<Union>
{
    std::set<std::shared_ptr<Event>> children;

    Union() : Event(Event::Union) {}

    void reduceChildren()
    {
        auto it = children.begin();
        while (it != children.end())
        {
            if ((*it)->getType() == Event::Union)
            {
                auto other = std::static_pointer_cast<Union>(*it);
                for (auto child : other->children)
                {
                    children.insert(child);
                }
                it = children.erase(it);
            }

            ++it;
        }
    }

    void reduceSiblings()
    {
        auto it1 = children.begin();
        while (it1 != children.end())
        {
            auto it2 = children.begin();
            while (it2 != children.end())
            {
                if (it1 == it2)
                {
                    ++it2;
                    continue;
                }

                if ((*it1)->dump() == (*it2)->dump())
                    it2 = children.erase(it2);
                else
                    ++it2;
            }

            ++it1;
        }
    }

    virtual void reduce()
    {
        for (auto & child : children)
            child->reduce();

        reduceChildren();
        // Reducing twice is necessary
        reduceChildren();
    }

    virtual std::string dump()
    {
        std::stringstream sstream;

        auto it = children.begin();
        while (it != children.end())
        {
            sstream << "(" << (*it)->dump() << ")";
            if (++it != children.end())
                sstream << " ⋃ ";
        }

        return sstream.str();
    }
};

struct DifferenceEvent :
    public Event,
    public std::enable_shared_from_this<DifferenceEvent>
{
    // x ≠ y
    Index x, y;

    DifferenceEvent() : Event(Event::DifferenceEvent) {}
    DifferenceEvent(Index const & x, Index const & y) :
        Event(Event::DifferenceEvent),
        x(x),
        y(y)
    {}

    virtual std::string dump()
    {
        std::stringstream sstream;
        sstream << "f(" << x.r << ", " << x.c << ")≠" << "f(" << y.r << ", " << y.c << ")";

        return sstream.str();
    }

    virtual void reduce()
    {
        // Nothing to do
    }
};

struct EqualityEvent :
    public Event,
    public std::enable_shared_from_this<EqualityEvent>
{
    // x = y
    Index x, y;

    EqualityEvent() : Event(Event::EqualityEvent) {}
    EqualityEvent(Index const & x, Index const & y) :
        Event(Event::EqualityEvent),
        x(x),
        y(y)
    {}

    virtual std::string dump()
    {
        std::stringstream sstream;
        sstream << "f(" << x.r << ", " << x.c << ")=" << "f(" << y.r << ", " << y.c << ")";

        return sstream.str();
    }

    virtual void reduce()
    {
        // Nothing to do
    }
};

struct N
{
    std::shared_ptr<Inter> inter;

    N() :
        inter(new Inter())
    {
    }

    std::vector<std::pair<N, int>> split()
    {
        std::vector<std::pair<N, int>> result;

        if (inter->children.size() > 1)
        {
            N n1, n2, n3;

            auto it = inter->children.begin();
            n1.inter->children.insert(*it);
            ++it;

            while (it != inter->children.end())
            {
                n2.inter->children.insert(*it);
                ++it;
            }

            auto it1 = inter->children.begin();
            auto it2 = it1;
            ++it2;
            while (it2 != inter->children.end())
            {
                std::shared_ptr<Union> u(new Union());
                u->children.insert(*it1);
                u->children.insert(*it2);
                n3.inter->children.insert(u);

                ++it2;
            }

            n1.inter->reduce();
            n2.inter->reduce();
            n3.inter->reduce();

            result.push_back(std::make_pair(n1, 1));
            result.push_back(std::make_pair(n2, 1));
            result.push_back(std::make_pair(n3, -1));
        }
        else
        {
            result.push_back(std::make_pair(*this, 1));
        }

        return result;
    }
};

std::ostream & operator<<(std::ostream & os, N const & n)
{
    os << "N(" << n.inter->dump() << ")";

    return os;
}

std::ostream & operator<<(std::ostream & os, std::vector<std::pair<N, int>> const & ns)
{
    auto it = ns.begin();

    while (it != ns.end())
    {
        if (it->second < 0)
            os << " - ";
        else if (it != ns.begin())
            os << " + ";

        os << it->first;

        ++it;
    }

    return os;
}

std::vector<std::pair<N, int>> definitiveSplit(std::vector<std::pair<N, int>> ns)
{
    if (ns.size() == 0)
        return ns;

    while (true)
    {
        bool changed = false;
        std::vector<std::pair<N, int>> result;

        for (auto nPair : ns)
        {
            N n = nPair.first;
            if (n.inter->children.size() > 1)
            {
                changed = true;
                auto v = n.split();

                if (v.size() != 3)
                    throw "What !? A split of size not equal to 3 !?";

                result.push_back(std::pair<N, int>(v[0].first, v[0].second * nPair.second));
                result.push_back(std::pair<N, int>(v[1].first, v[1].second * nPair.second));
                result.push_back(std::pair<N, int>(v[2].first, v[2].second * nPair.second));
            }
            else
            {
                result.push_back(nPair);
            }
        }

        std::cout << result.size() << std::endl;
        ns = result;

        if (!changed)
            break;
    }

    return ns;
}

typedef std::vector<int> polynome;

std::ostream & operator<<(std::ostream & os, polynome const & p)
{
    std::cout << "p = [";
    auto it = p.begin();
    while (it != p.end())
    {
        std::cout << *it;

        if (++it != p.end())
            std::cout << ", ";
    }
    std::cout << "];";

    return os;
}

polynome operator*(int k, polynome p)
{
    polynome result;

    for (auto coeff : p)
        result.push_back(coeff * k);

    return result;
}

polynome operator+(polynome p1, polynome p2)
{
    polynome result;

    auto it1 = p1.begin();
    auto it2 = p2.begin();

    while (it1 != p1.end() || it2 != p2.end())
    {
        if (it1 != p1.end() && it2 != p2.end())
        {
            result.push_back(*it1 + *it2);
            ++it1;
            ++it2;
        }
        else if (it1 != p1.end())
        {
            result.push_back(*it1);
            ++it1;
        }
        else if (it2 != p2.end())
        {
            result.push_back(*it2);
            ++it2;
        }
    }

    return result;
}

polynome & operator+=(polynome & p1, polynome p2)
{
    p1 = p1 + p2;

    return p1;
}

polynome getPolynomeFromGroups(std::map<Index, std::set<Index>> groups, int totalSquares)
{
    polynome p;

    while (true)
    {
        bool changed = false;

        auto it1 = groups.begin();
        while (it1 != groups.end())
        {
            auto it2 = groups.begin();
            while (it2 != groups.end())
            {
                if (it1 == it2)
                {
                    ++it2;
                    continue;
                }

                if (it1->second.find(it2->first) != it1->second.end())
                {
                    changed = true;
                    it1->second.insert(it2->second.begin(), it2->second.end());
                    it2 = groups.erase(it2);
                    continue;
                }
                else
                {
                    for (auto x : it2->second)
                    {
                        if (it1->second.find(x) != it1->second.end())
                        {
                            changed = true;
                            it1->second.insert(it2->second.begin(), it2->second.end());
                            it2 = groups.erase(it2);
                            break;
                        }
                    }
                }
                ++it2;
            }

            ++it1;
        }

        if (!changed)
            break;
    }

    int remainingBlocks = totalSquares;
    for (auto group : groups)
        remainingBlocks -= group.second.size();
    remainingBlocks += groups.size();

    if (remainingBlocks <= 0)
    {
        std::cout << "dumping groups before terminating:" << std::endl;

        for (auto group : groups)
        {
            std::cout << group.first << ": ";
            for (auto x : group.second)
                std::cout << x << ", ";
            std::cout << std::endl;
        }

        std::cout << "groups " << groups.size() << std::endl;
        throw "0 remainingBlocks shouldn’t happen";
    }

    for (int i = 0 ; i <= totalSquares ; ++i)
    {
        if (i == remainingBlocks)
            p.push_back(-1);
        else if (i == totalSquares)
            p.push_back(1);
        else
            p.push_back(0);
    }

    // for (auto group : groups)
    // {
    //     for (auto index : group.second)
    //     {
    //         std::cout << index << ", ";
    //     }
    //     std::cout << std::endl;
    // }

    return p;
}

polynome getPolynomeFromN(N const & n, int totalSquares)
{
    if (n.inter->children.size() > 1)
        throw "Don’t get polynome from an intersection N";

    polynome p;

    if ((*n.inter->children.begin())->getType() == Event::Union)
    {
        std::map<Index, std::set<Index>> groups;
        for (auto diff : std::static_pointer_cast<Union>(*n.inter->children.begin())->children)
        {
            if (diff->getType() != Event::DifferenceEvent)
                throw "Children of union must be a DifferenceEvent here";

            auto d = std::static_pointer_cast<DifferenceEvent>(diff);
            groups[d->x].insert(d->y);
            groups[d->y].insert(d->x);
        }

        return getPolynomeFromGroups(groups, totalSquares);
    }
    else if ((*n.inter->children.begin())->getType() == Event::DifferenceEvent)
    {
        for (int i = 0 ; i < totalSquares ; ++i)
        {
            if (i == totalSquares - 1)
                p.push_back(-1);
            else
                p.push_back(0);
        }
        p.push_back(1);
    }
    else
        throw "Intersection must have either a Union or a DifferenceEvent child";

    return p;
}

int main()
{
#if 0

    int rows = 2, cols = 2;

    N n;
    std::shared_ptr<Inter> inter(new Inter());

    for (int r = 0 ; r < rows ; ++r)
    {
        for (int c = 0 ; c < cols ; ++c)
        {
            if (r + 1 < rows)
                inter->children.insert(
                    std::shared_ptr<DifferenceEvent>(new DifferenceEvent(Index(r, c), Index(r+1, c))));
            if (c + 1 < cols)
                inter->children.insert(
                    std::shared_ptr<DifferenceEvent>(new DifferenceEvent(Index(r, c), Index(r, c + 1))));
        }
    }

    n.inter = inter;
    n.inter->reduce();

    n.split();

    std::vector<std::pair<N, int>> ns;
    ns.push_back(std::make_pair(n, 1));
    ns = definitiveSplit(ns);

    std::cout << ns << std::endl;

    n = ns.rbegin()->first;

    std::cout << n.inter->dump() << std::endl;

    n.inter->reduce();

    std::cout << n.inter->dump() << std::endl;

#else

    for (int rows = 2 ; rows < 5 ; ++rows)
    {
        for (int cols = rows ; cols < 5 ; ++cols)
        {
            N n;
            std::shared_ptr<Inter> inter(new Inter());

            for (int r = 0 ; r < rows ; ++r)
            {
                for (int c = 0 ; c < cols ; ++c)
                {
                    if (r + 1 < rows)
                        inter->children.insert(
                            std::shared_ptr<DifferenceEvent>(new DifferenceEvent(Index(r, c), Index(r+1, c))));
                    if (c + 1 < cols)
                        inter->children.insert(
                            std::shared_ptr<DifferenceEvent>(new DifferenceEvent(Index(r, c), Index(r, c + 1))));
                }
            }

            n.inter = inter;
            n.inter->reduce();

            std::vector<std::pair<N, int>> ns;
            ns.push_back(std::make_pair(n, 1));
            ns = definitiveSplit(ns);

            // std::cout << ns << std::endl;

            polynome lastResult;
            for (auto nPair : ns)
            {
                // std::cout << nPair.second * getPolynomeFromN(nPair.first, rows * cols) << std::endl;
                lastResult += nPair.second * getPolynomeFromN(nPair.first, rows * cols);
            }

            std::cout << rows << ", " << cols << ": " << lastResult << std::endl;
        }
    }

#endif

    return 0;
}
