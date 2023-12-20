#include <iostream>

struct ExpertRequirement {
    char sign[2] = {' ', '='};
    int rate;
    int localOptimal;
};

struct Subject {
    int qt;
    ExpertRequirement * expReq;


};


int main() {
    int t;

    std::cin >> t;
    if (!(1 <= t && t <= 10*10*10))
        return 0;

    Subject * subjects = new Subject[t];

    for (int i = 0; i < t; i++) {
        int n;
        std::cin >> n;
        if (!(1 <= n && n <= 10 * 10 * 10))
            break;

        subjects[i].expReq = new ExpertRequirement[n];
        subjects[i].qt = n;

        for (int j = 0; j < n; j++) {
            char sign[2];
            int a;
            std::cin >> sign[0];
            std::cin >> sign[1];

            std::cin >> a;

            if (!(15 <= a && a <= 30 && sign[1] == '=')) {
                delete[] subjects[i].expReq;
                delete[] subjects;
                return 0;
            }

            subjects[i].expReq[j].sign[0] = sign[0];
            subjects[i].expReq[j].rate = a;
            subjects[i].expReq[j].localOptimal = a;

        }
    }

    for (int i = 0; i < t; i++) {
        int min = 15;
        int max = 30;

        for (int j = 0; j < subjects[i].qt; j++) {
            ExpertRequirement * expReq = subjects[i].expReq;

            switch (expReq[j].sign[0]) {
                case '<':
                    if (max >= expReq[j].rate) {
                        max = expReq[j].rate;
                    }

                    break;

                case '>':
                    if (min <= expReq[j].rate) {
                        min = expReq[j].rate;
                    }

                    break;
            }
            if (min <= max) {
                expReq[j].localOptimal = min;
            } else {
                expReq[j].localOptimal = -1;
            }

        }

    }
    for (int i = 0; i < t; i++) {
        for (int j = 0; j < subjects[i].qt; j++) {
            std::cout << subjects[i].expReq[j].localOptimal << "\n";
        }
        delete [] subjects[i].expReq;
    }

    delete [] subjects;


    return 0;
}



