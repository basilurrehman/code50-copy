#include <iostream>
using namespace std;

const char* sportcnv(char sporttemp)
{
    // const char* f = "football";
    // const char* c = "cricket";
    // const char* h = "hockey";
    const char* sport;
    if(sporttemp=='c')
    sport= "cricket";
    else if (sporttemp=='f')
    sport="football";
    else if(sporttemp=='h')
    sport="hockey";
    return sport;
}

int main()
{
    int maxrec = 10;
    int* idrec = (int*)calloc(maxrec, sizeof(int));
    const char **sportrec = (const char**)calloc(maxrec, sizeof(char*)*9);
    int id;
    char sporttemp;
    bool enrolled = false;
    bool exit = false;

    do{
    cout << "press 0 for all records";
    cout << "\nEnter ID to view, enroll, update, or delete";
    cout << "\nPRess e for exit\n";
    cin >> id;
    if (id == 0)
    {
        for (int i = 0; i < maxrec; i++)
        {
            if(idrec[i]==0)
            break;
            cout << idrec[i] << "    " << sportrec[i]<< endl;
        }

    }

    else
    {
        cout << id << " is enrolled in: ";
        for (int i = 0; i < maxrec; i++)
        {
            if (idrec[i] == id)
            {
                cout << sportrec[i];
                enrolled = true;
                cout << "\nPress the letter if you like to tranfer in other available sports \n 1.c for cricket \n 2.f for football \n 3.h for hockey \n 4.d for delete\n //5. b for back";
                cin >> sporttemp;
                if(sporttemp == 'd')
                {
                    for (int j = i; idrec[j]!=0;j++)
                    {
                        idrec[j]=idrec[j+1];
                        sportrec[j]=sportrec[j+1];
                    }
                }
                else if(sporttemp== 'c' || sporttemp== 'f' || sporttemp=='h')
                {
                    const char* sport = sportcnv(sporttemp);
                    for (int j=i; j<maxrec;j++)
                    {
                        idrec[j]=idrec[j+1];
                        sportrec[j]=sportrec[j+1];
                        if(idrec[j]==0)
                        {
                            idrec[j]=id;
                            sportrec[j]=sport;
                            break;
                        }
                    }
                }
            break;
            }
            else if (idrec[i]==0)
            {
                cout << "nothing\n";
                cout << "Press the letter if you like to enroll in these available sports \n 1.c for cricket \n 2.f for football \n 3.h for hockey \n //4.d for depart\n";
                cin >> sporttemp;
                if(sporttemp== 'c' || sporttemp== 'f' || sporttemp=='h')
                {
                    const char* sport = sportcnv(sporttemp);
                    idrec[i]=id;
                    sportrec[i]=sport;
                    break;
                }
                break;
            }
            if (i==maxrec-1 && idrec[i]!=0)
            {
                maxrec+=10;
                idrec = (int*)realloc(idrec, maxrec * sizeof(int));
                sportrec = (const char**)realloc(sportrec, maxrec * sizeof(char*) * 9);
                for(int k = maxrec-10;k<=maxrec;k++)
                {
                    idrec[k] = 0;
                    sportrec[k] = 0;
                }
            }
        }
    }
    }while(exit==false);
    free(sportrec);
    free(idrec);
}
