#include <bits/stdc++.h>

using namespace std;

int main()
{
    int N, Q;
    std::cin >> N;
    std::cin >> Q;

    std::vector<int> pembalap(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> pembalap[i];
    }

    vector<int> switcher(Q);
    for (int i = 0; i < Q; i++)
    {
        std::cin >> switcher[i];
    }

    /* BISMILLAH*/
    

    /* YA ALLAH */
    int total_pembalap = pembalap.size();
    if(total_pembalap > 0)
    {
        std::cout << total_pembalap << " " << pembalap.at(0) << std::endl;
    }
    else
    {
        std::cout << "Tidak ada pemenang" << std::endl;
    }

    return 0;
}