#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class tree
{
public:
    unsigned sum;
    vector<pair<string, double> > average;
    map<string, unsigned> category;
    
    void update_tree(string name);
    unsigned get_sum(void);
    void evaluate_average(void);
    void print_average(void);
};

int main(void)
{
    tree t;
    while(1)
    {
        string tree_name;
        if(!getline(cin, tree_name)) break;
        t.update_tree(tree_name);
    }
    t.evaluate_average();
    t.print_average();
    return 0;
}

void tree::update_tree(string name)
{
    this->category[name] += 1;
}

unsigned tree::get_sum(void)
{
    this->sum = 0;
    for(auto it = this->category.begin() ; it != this->category.end() ; it++)
    {
        sum += it->second;
    }
    return sum;
}

void tree::evaluate_average(void)
{
    unsigned total = this->get_sum();
    for(auto it = this->category.begin() ; it != this->category.end() ; it++)
    {
        average.push_back({ it->first, ((double)it->second / (total)) * 100 });
    }
}

void tree::print_average(void)
{
    cout << fixed;
    cout.precision(4);
    for(int i = 0 ; i < this->average.size() ; i++)
    {
        cout << this->average[i].first << ' ' << this->average[i].second << '\n';
    }
}