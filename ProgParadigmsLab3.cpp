#include <iostream>
#include <thread>
#include <vector>
#include <semaphore>
#include <syncstream>

using namespace std;

vector<string> actionSets = { "a", "b", "c", "d", "e", "f", "g", "h", "i", "j" };

counting_semaphore<6> SetA{ 0 };
counting_semaphore<9> SetB{ 0 };
counting_semaphore<8> SetC{ 0 };
counting_semaphore<7> SetD{ 0 };
counting_semaphore<5> SetE{ 0 };
counting_semaphore<6> SetF{ 0 };
counting_semaphore<8> SetG{ 0 };
counting_semaphore<6> SetH{ 0 };
counting_semaphore<6> SetI{ 0 };

int A = 0;
int B = 0;
int C = 0;
int D = 0;
int E = 0;
int F = 0;
int G = 0;
int H = 0;
int I = 0;


void f(const string& actionSet, int actionNumber) {
    osyncstream bout(cout);
    bout << "From the set " << actionSet << " performed action " << actionNumber << ".\n";
    bout.emit();
}

void NT1() {
    for (int i = 1; i <= 5; i += 2) {
        f(actionSets[0], i);
        A++;
    }
    while (A<=6) {
        if (A == 6) {
            SetA.release();
            break;
        }
    }
    SetA.acquire();
    for (int i = 1; i <= 7; i += 2) {
        f(actionSets[2], i);
        C++;
    }
    f(actionSets[3], 6);
    D++;

    while (C <= 8) {
        if (C == 8) {
            SetC.release();
            break;
        }
    }
    SetC.acquire();
    for (int i = 1; i <= 7; i += 2) {
        f(actionSets[6], i);
        G++;
    }

    while (G <= 8 && H <= 6 && I <= 6) {
        if (G == 8 && H == 6 && I == 6) {
            SetG.release();
            SetH.release();
            SetI.release();
            break;
        }
    }
    SetG.acquire();
    SetH.acquire();
    SetI.acquire();
    for (int i = 1; i <= 6; i += 5) {
        f(actionSets[9], i);
    }
}

void NT2() {
    for (int i = 2; i <= 6; i += 2) {
        f(actionSets[0], i);
        A++;
    }
    while (A <= 6) {
        if (A == 6) {
            SetA.release();
            break;
        }
    }
    SetA.acquire();
    for (int i = 2; i <= 8; i += 2) {
        f(actionSets[2], i);
        C++;
    }
    f(actionSets[3], 7);
    D++;
    while (C <= 8) {
        if (C == 8) {
            SetC.release();
            break;
        }
    }
    SetC.acquire();
    for (int i = 2; i <= 8; i += 2) {
        f(actionSets[6], i);
        G++;
    }
    while (G <= 8 && H <= 6 && I <= 6) {
        if (G == 8 && H == 6 && I == 6) {
            SetG.release();
            SetH.release();
            SetI.release();
            break;
        }
    }
    SetG.acquire();
    SetH.acquire();
    SetI.acquire();
    for (int i = 2; i <= 7; i += 5) {
        f(actionSets[9], i);
    }
}


void NT3() {
    for (int i = 1; i <= 7; i += 3) {
        f(actionSets[1], i);
        B++;
    }
    while (A <= 6) {
        if (A == 6) {
            SetA.release();
            break;
        }
    }
    SetA.acquire();
    for (int i = 1; i <= 5; ++i) {
        f(actionSets[3], i);
        D++;
    }
    while (D <= 7 && E <= 5) {
        if (D == 7 && E == 5) {
            SetD.release();
            SetE.release();
            break;
        }
    }
    SetD.acquire();
    SetE.acquire();
    for (int i = 1; i <= 5; i += 2) {
        f(actionSets[7], i);
        H++;
    }
    while (F<= 6) {
        if (F == 6) {
            SetF.release();
            break;
        }
    }
    SetF.acquire();
    f(actionSets[8], 4);
    I++;

    while (G <= 8 && H <= 6 && I <= 6) {
        if (G == 8 && H == 6 && I == 6) {
            SetG.release();
            SetH.release();
            SetI.release();
            break;
        }
    }
    SetG.acquire();
    SetH.acquire();
    SetI.acquire();
    for (int i = 3; i <= 8; i += 5) {
        f(actionSets[9], i);
    }
}

void NT4() {
    for (int i = 2; i <= 8; i += 3) {
        f(actionSets[1], i);
        B++;
    }
    while (B <= 9) {
        if (B == 9) {
            SetB.release();
            break;
        }
    }
    SetB.acquire();
    for (int i = 1; i <= 5; ++i) {
        f(actionSets[4], i);
        E++;
    }
    while (D <= 7 && E <= 5) {
        if (D == 7 && E == 5) {
            SetD.release();
            SetE.release();
            break;
        }
    }
    SetD.acquire();
    SetE.acquire();
    for (int i = 2; i <= 6; i += 2) {
        f(actionSets[7], i);
        H++;
    }
    while (F <= 6) {
        if (F == 6) {
            SetF.release();
            break;
        }
    }
    SetF.acquire();
    f(actionSets[8], 5);
    I++;
    while (G <= 8 && H <= 6 && I <= 6) {
        if (G == 8 && H == 6 && I == 6) {
            SetG.release();
            SetH.release();
            SetI.release();
            break;
        }
    }
    SetG.acquire();
    SetH.acquire();
    SetI.acquire();
    f(actionSets[9], 4);
}

void NT5() {
    for (int i = 3; i <= 9; i += 3) {
        f(actionSets[1], i);
        B++;
    }
    while (B <= 9) {
        if (B == 9) {
            SetB.release();
            break;
        }
    }
    SetB.acquire();
    for (int i = 1; i <= 6; ++i) {
        f(actionSets[5], i);
        F++;
    }
    while (F <= 6) {
        if (F == 6) {
            SetF.release();
            break;
        }
    }
    SetF.acquire();
    for (int i = 1; i <= 3; ++i) {
        f(actionSets[8], i);
        I++;
    }
    f(actionSets[8], 6);
    I++;

    while (G <= 8 && H <= 6 && I <= 6) {
        if (G == 8 && H == 6 && I == 6) {
            SetG.release();
            SetH.release();
            SetI.release();
            break;
        }
    }
    SetG.acquire();
    SetH.acquire();
    SetI.acquire();
    f(actionSets[9], 5);
}

int main() {
    cout << "The calculation has started.\n";
    thread nt1(NT1);
    thread nt2(NT2);
    thread nt3(NT3);
    thread nt4(NT4);
    thread nt5(NT5);

    nt1.join();
    nt2.join();
    nt3.join();
    nt4.join();
    nt5.join();
    cout << "The calculation is complete.\n";
    return 0;
}
