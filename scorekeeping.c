#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter number of teams N \n");
    int n; scanf("%d",&n);
    int Nn=n/2;
    int N = 2*(Nn*(Nn-1))/2;
     // (N/2)c2 matches in every subgroup


     struct match_played {
        int match_id;
        char teams_played[3];
        int highest_run;
        int man_of_the_match;
        int wicket_taken_by_pacer;
        int match_result;
    }c[N];

    struct team {
    int no;
    struct player{
            int player_id;
            int match_id;
            int matches;
            int previous_total_score;
            int previous_avg;
            int previous_total_wickets;
            int previous_wicket_avg;
            int total_runs_in_last_five_matches;
            int century;
            int present_match_score;
            int player_role;
            int status;
            }b[15];
    int pacers;
    int spinners;
    }a[n];

    /* Initialize all players */
    int count_of_id=0;
    for(int i=0;i<n;i++)
    {
        a[i].no=0; // initializing counter for number of matches played by each team to 0
        a[i].pacers=0; // initiliazing all spinners and pacers wicket counts to 0
        a[i].spinners=0;
        printf("Enter pre-tournament stats for team %d\n",i);
        for(int j=0;j<15;j++)
        {
            printf("Enter player status for player id %d-> 0.Batsmen 1.Bowler 2.All Rounder\n",count_of_id);
            scanf("%d",&a[i].b[j].player_role);
            //a[i].b[j].player_role = 1;
            a[i].b[j].player_id= count_of_id; count_of_id++;
            a[i].b[j].previous_total_score=0;
            a[i].b[j].previous_avg=0;
            a[i].b[j].previous_total_wickets=0;
            a[i].b[j].previous_wicket_avg=0;
            a[i].b[j].total_runs_in_last_five_matches=0;
            a[i].b[j].century=0;
            a[i].b[j].matches=0;
            a[i].b[j].present_match_score=0;
        }
    }
    system("cls");


    printf("The teams will be divided into two subgroups of %d teams each\n",n/2);
    printf("The matches for the first %d teams are\n",n/2);

    printf("Matches of first group are as following\n");
    int i,j; int count=0; int spaac;
    for(i=0;i<n/2-1;i++)
    {
        for(int j=i+1;j<n/2;j++)
        {
            int max_run=0;
            printf("Match ID is %d\n",count);
            c[count].match_id = count +1 ;


            printf("Match played is between %d and %d\n",i,j);

            printf("Enter -1 anytime you want to exit from batsmen/bowling lineup\n");
            //c[count].teams_played = i&j;
            int tempo=0;
            printf("Enter team %d stats\n",i); a[i].no++; // increasing count of number of matches
            for(int k=0;k<15;k++)
            {
                    printf("Enter the runs scored by player %d \t",a[i].b[k].player_id);
                    scanf("%d",&tempo);
                    if(tempo==-1){
                        a[i].b[k].present_match_score=0;
                    }
                    else {
                    a[i].b[k].present_match_score = tempo;

                    if(a[i].b[k].present_match_score >=100) a[i].b[k].century++;

                    a[i].b[k].previous_total_score+= a[i].b[k].present_match_score;
                    a[i].b[k].matches++;
                    if(a[i].b[k].present_match_score > max_run)
                        max_run = a[i].b[k].present_match_score;

                    printf("Enter 1 if player was out or 0 if he was not\t");
                    scanf("%d",&a[i].b[k].status);
                    }
            }

            for(int k=0;k<15;k++)
            {
                    int wicks,wickruns;
                    printf("Enter wickets taken by player %d \t",a[i].b[k].player_id);
                    scanf("%d",&wicks);
                    if(wicks == -1) {}
                    else {
                    printf("Enter the runs conceded by player %d \t",a[i].b[k].player_id);
                    scanf("%d",&wickruns);

                    printf("Enter 1 if spinner or 2 if pacer\n");
                    scanf("%d",&spaac);
                    if(spaac==1) a[i].spinners+=wicks;
                    else a[i].pacers+=wicks;


                    a[i].b[k].previous_total_wickets+=wicks;
                    a[i].b[k].matches++;
                    }
            }




            printf("\nEnter team %d stats\n",j); a[j].no++; // increasing count of number of matches
            for(int k=0;k<15;k++)
            {
                    printf("Enter the runs score by player %d\t",a[j].b[k].player_id);
                    scanf("%d",&tempo);
                    if(tempo==-1) { a[j].b[k].present_match_score=0;}
                    else {
                    a[j].b[k].present_match_score=tempo;

                    if(a[j].b[k].present_match_score >=100) a[j].b[k].century++;

                    a[j].b[k].previous_total_score+= a[j].b[k].present_match_score;
                    a[j].b[k].matches++;
                    if(a[j].b[k].present_match_score > max_run)
                        max_run = a[j].b[k].present_match_score;

                    printf("Enter 1 if player was out or 0 if he was not\t");
                    scanf("%d",&a[j].b[k].status);
                    }
            }

            for(int k=0;k<15;k++)
            {
                    int wicks,wickruns;
                    printf("Enter wickets taken by player %d\t",a[j].b[k].player_id);
                    scanf("%d",&wicks);
                    if(wicks==-1) {}
                    else{
                    printf("Enter the runs conceded by player %d\t",a[j].b[k].player_id);
                    scanf("%d",&wickruns);

                    printf("Enter 1 if spinner or 2 if pacer\n");
                    scanf("%d",&spaac);
                    if(spaac==1) a[j].spinners+=wicks;
                    else a[j].pacers+=wicks;

                    a[j].b[k].previous_total_wickets+=wicks;
                    }
            }

            printf("Enter the team number which won the match\n");
            scanf("%d",&c[count].match_result);

            printf("Enter Player ID for Man of the Match\n");
            scanf("%d",&c[count].man_of_the_match);
            count++;
            printf("Maximum run scored is %d\n",max_run);
            c[count].highest_run = max_run;
        }

    }

    printf("\nMatches of second group are as following");
    for(i=n/2;i<n-1;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int max_run=0;
            printf("\nMatch ID is %d",count);
            c[count].match_id = count +1 ;


            printf("\nMatch played is between %d and %d\n",i,j);
            //c[count].teams_played = i&j;
            int tempo=0;
            printf("Enter team %d stats\n",i); a[i].no++; //increasing count of number of matches
            for(int k=0;k<15;k++)
            {
                    printf("Enter the runs scored by player %d \t",a[i].b[k].player_id);
                    scanf("%d",&tempo);
                    if(tempo==-1) { a[i].b[k].present_match_score=0;}
                    else {
                    a[i].b[k].present_match_score=tempo;

                    if(a[i].b[k].present_match_score >=100) a[i].b[k].century++;

                    a[i].b[k].previous_total_score+= a[i].b[k].present_match_score;
                    a[i].b[k].matches++;
                    if(a[i].b[k].present_match_score > max_run)
                        max_run = a[i].b[k].present_match_score;

                    printf("Enter 1 if player was out or 0 if he was not\t");
                    scanf("%d",&a[i].b[k].status);
                    }
            }

            for(int k=0;k<15;k++)
            {
                    int wicks,wickruns;
                    printf("Enter wickets taken by player %d \t",a[i].b[k].player_id);
                    scanf("%d",&wicks);
                    if(wicks==-1){}
                    else {
                    printf("Enter the runs conceded by player %d \t",a[i].b[k].player_id);
                    scanf("%d",&wickruns);

                    printf("Enter 1 if spinner or 2 if pacer\n");
                    scanf("%d",&spaac);
                    if(spaac==1) a[i].spinners+=wicks;
                    else a[i].pacers+=wicks;

                    a[i].b[k].previous_total_wickets+=wicks;
                    }
            }




            printf("Enter team %d stats\n",j); a[j].no++;
            for(int k=0;k<15;k++)
            {
                    printf("Enter the runs score by player %d\t",a[j].b[k].player_id);
                    scanf("%d",&tempo);
                    if(tempo==-1) {a[j].b[k].present_match_score=0;}
                    else {
                    a[j].b[k].present_match_score=tempo;

                    if(a[j].b[k].present_match_score >=100) a[j].b[k].century++;

                    a[j].b[k].previous_total_score+= a[j].b[k].present_match_score;
                    a[j].b[k].matches++;
                    if(a[j].b[k].present_match_score > max_run)
                        max_run = a[j].b[k].present_match_score;

                    printf("Enter 1 if player was out or 0 if he was not\t");
                    scanf("%d",&a[j].b[k].status);
                    }
            }

            for(int k=0;k<15;k++)
            {
                    int wicks,wickruns;
                    printf("Enter wickets taken by player %d\t",a[j].b[k].player_id);
                    scanf("%d",&wicks);
                    if(wicks==-1) {}
                    else{
                    printf("Enter the runs conceded by player %d\t",a[j].b[k].player_id);
                    scanf("%d",&wickruns);

                    printf("Enter 1 if spinner or 2 if pacer\n");
                    scanf("%d",&spaac);
                    if(spaac==1) a[j].spinners+=wicks;
                    else a[j].pacers+=wicks;

                    a[j].b[k].previous_total_wickets+=wicks;
                    }
            }

            printf("Enter the team number which won the match\n");
            scanf("%d",&c[count].match_result);

            printf("Enter Player ID for Man of the Match\n");
            scanf("%d",&c[count].man_of_the_match);
            count++;
            printf("Maximum run scored is %d\n",max_run);
            c[count].highest_run = max_run;
        }

    }

    system("cls");

    int teamno=0; int ijk=0;
    while(teamno!=-1){
        printf("Enter the team number whose possible team combination of players you want to find out or enter -1 if you want to exit\n");
        scanf("%d",&teamno);

        if(teamno ==-1) break;
        struct player temp;

         for(int i=0;i<14;i++) // sorting in descending order by buuble sort on basis of previous total run score for only batsmen
         {
             for(int j=0;j<14-i;j++)
             {
                 if(a[teamno].b[j].previous_total_score < a[teamno].b[j+1].previous_total_score &&
                    ( (a[teamno].b[j].player_role ==0 || a[teamno].b[j].player_role ==2)   && (a[teamno].b[j+1].player_role==0 ||
                                                                                               a[teamno].b[j+1].player_role==2) ) )
                 {
                     temp = a[teamno].b[j];
                     a[teamno].b[j]=a[teamno].b[j+1];
                     a[teamno].b[j+1]=temp;
                 }
             }
         }
            printf("\nFirst possible combination is\n");
            ijk=0;
            for(int i=0;i<15;i++)
            {
                if(ijk==7) break;
                if(a[teamno].b[i].player_role==0 || a[teamno].b[i].player_role==2 )
                {
                    printf("%d\n",a[teamno].b[i].player_id);
                    ijk++;
                }
            }

         for(int i=0;i<14;i++) // sorting in descending order by buuble sort on basis of previous total wicket for only bowlers
         {
             for(int j=0;j<14-i;j++)
             {
                 if(a[teamno].b[j].previous_total_wickets < a[teamno].b[j+1].previous_total_wickets &&
                    ( ( a[teamno].b[j].player_role==1 || a[teamno].b[j].player_role ==2) && ( a[teamno].b[j+1].player_role==1 ||
                                                                                             a[teamno].b[j].player_role ==2) ) )
                 {
                     temp = a[teamno].b[j];
                     a[teamno].b[j]=a[teamno].b[j+1];
                     a[teamno].b[j+1]=temp;
                 }
             }
         }
            ijk=0;
            for(int i=0;i<15;i++)
            {
                if(ijk==4) break;
                if(a[teamno].b[i].player_role==1 || a[teamno].b[i].player_role==2 )
                {
                    printf("%d\n",a[teamno].b[i].player_id);
                    ijk++;
                }
            }
            // sorting a[teamno].b-> array
         //sort by batsmen and pick 7 then sort by bowlers and pick 4



         for(int i=0;i<14;i++) // sorting in descending order by buuble sort on basis of previous total run score for only batsmen
         {
             for(int j=0;j<14-i;j++)
             {
                 if(a[teamno].b[j].previous_total_score < a[teamno].b[j+1].previous_total_score &&
                    ( (a[teamno].b[j].player_role ==0 || a[teamno].b[j].player_role ==2)   && (a[teamno].b[j+1].player_role==0 ||
                                                                                               a[teamno].b[j+1].player_role==2) ) )
                 {
                     temp = a[teamno].b[j];
                     a[teamno].b[j]=a[teamno].b[j+1];
                     a[teamno].b[j+1]=temp;
                 }
             }
         }
            printf("\nSecond possible combination is\n");
            ijk=0;
            for(int i=0;i<15;i++)
            {
                if(ijk==5) break;
                if(a[teamno].b[i].player_role==0 || a[teamno].b[i].player_role==2 )
                {
                    printf("%d\n",a[teamno].b[i].player_id);
                    ijk++;
                }
            }

         for(int i=0;i<14;i++) // sorting in descending order by buuble sort on basis of previous total wicket for only bowlers
         {
             for(int j=0;j<14-i;j++)
             {
                 if(a[teamno].b[j].previous_total_wickets < a[teamno].b[j+1].previous_total_wickets &&
                    ( ( a[teamno].b[j].player_role==1 || a[teamno].b[j].player_role ==2) && ( a[teamno].b[j+1].player_role==1 ||
                                                                                             a[teamno].b[j].player_role ==2) ) )
                 {
                     temp = a[teamno].b[j];
                     a[teamno].b[j]=a[teamno].b[j+1];
                     a[teamno].b[j+1]=temp;
                 }
             }
         }
            ijk=0;
            for(int i=0;i<15;i++)
            {
                if(ijk==6) break;
                if(a[teamno].b[i].player_role==1 || a[teamno].b[i].player_role==2 )
                {
                    printf("%d\n",a[teamno].b[i].player_id);
                    ijk++;
                }
            } // sort by batsmen and pick 5 then sort by bowlers and pick 6



         for(int i=0;i<14;i++) // sorting in descending order by buuble sort on basis of previous total run score for only batsmen
         {
             for(int j=0;j<14-i;j++)
             {
                 if(a[teamno].b[j].previous_total_score < a[teamno].b[j+1].previous_total_score &&
                    ( (a[teamno].b[j].player_role ==0 || a[teamno].b[j].player_role ==2)   && (a[teamno].b[j+1].player_role==0 ||
                                                                                               a[teamno].b[j+1].player_role==2) ) )
                 {
                     temp = a[teamno].b[j];
                     a[teamno].b[j]=a[teamno].b[j+1];
                     a[teamno].b[j+1]=temp;
                 }
             }
         }
            printf("\nThird possible combination is\n");
            ijk=0;
            for(int i=0;i<15;i++)
            {
                if(ijk==6) break;
                if(a[teamno].b[i].player_role==0 || a[teamno].b[i].player_role==2 )
                {
                    printf("%d\n",a[teamno].b[i].player_id);
                    ijk++;
                }
            }

         for(int i=0;i<14;i++) // sorting in descending order by buuble sort on basis of previous total wicket for only bowlers
         {
             for(int j=0;j<14-i;j++)
             {
                 if(a[teamno].b[j].previous_total_wickets < a[teamno].b[j+1].previous_total_wickets &&
                    ( ( a[teamno].b[j].player_role==1 || a[teamno].b[j].player_role ==2) && ( a[teamno].b[j+1].player_role==1 ||
                                                                                             a[teamno].b[j].player_role ==2) ) )
                 {
                     temp = a[teamno].b[j];
                     a[teamno].b[j]=a[teamno].b[j+1];
                     a[teamno].b[j+1]=temp;
                 }
             }
         }
            ijk=0;
            for(int i=0;i<15;i++)
            {
                if(ijk==5) break;
                if(a[teamno].b[i].player_role==1 || a[teamno].b[i].player_role==2 )
                {
                    printf("%d\n",a[teamno].b[i].player_id);
                    ijk++;
                }
            }// sort by batsmen and pick 6 then sort by bowlers and pick 5

        }
            int highest_run_getter=0; long long int  check_similarity=0; long long int check_similarity1=0;
            for(int i=0;i<n;i++) // to get highest run getter score
            {
                for(int j=0;j<15;j++)
                {
                    if(a[i].b[j].previous_total_score> highest_run_getter )
                        highest_run_getter=a[i].b[j].previous_total_score;
                }
            }
            printf("\nThe highest run getter is/are \n");
            for(int i=0;i<n;i++) // to print highest run getter score
            {
                for(int j=0;j<15;j++)
                {
                    if(a[i].b[j].previous_total_score == highest_run_getter )
                      {
                          check_similarity = check_similarity*10+ a[i].b[j].player_id;
                      printf("%d ",a[i].b[j].player_id);
                      }
                }
            }

            int no_of_man=0;       // to store award for each indv awardee
            int max_no_of_man=0; // to store max number of award
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(c[i].man_of_the_match==c[j].man_of_the_match)
                        { no_of_man++;}
                }
                if(max_no_of_man<no_of_man)
                    max_no_of_man=no_of_man;

            }
            max_no_of_man--;
            printf("\nThe player declared man of the match max number of times is\n");
            //printf("%d",max_no_of_man);
            for(int i=0;i<N;i++)
            {
                printf("%d\n",c[i].man_of_the_match);
            }
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(c[i].man_of_the_match==c[j].man_of_the_match)
                       {
                           no_of_man++;
                       }
                }
                if(max_no_of_man==no_of_man)
                   {
                       printf("%d ",c[i].man_of_the_match);
                       check_similarity1 = check_similarity1*10+ c[i].man_of_the_match;
                   }

            }
            double highestavg=0;
            double avg=0;

            for(int i=0;i<n;i++)
            {
                for(int j=0;j<15;j++)
                {
                    if(a[i].b[j].matches!=0)
                    avg = (a[i].b[j].previous_total_score)/(a[i].b[j].matches);
                    if(avg > highestavg)
                        highestavg=avg;
                }
            }

            printf("\nThe highest average is %lf\n\n",highestavg);

            teamno=0;
            while(teamno!=-1)
            {
                 printf("\nEnter the team number whose difference between pacers and spinners wicket count you want to know\n");
                 scanf("%d",&teamno);
                 if(teamno==-1) break;
                    printf("\nThe pacers took %d wickets and spinners took %d wickets\n",a[teamno].pacers,a[teamno].spinners);

                        if(a[teamno].pacers > a[teamno].spinners)
                        printf("Difference is %d\n",(a[teamno].pacers - a[teamno].spinners));
                        else if(a[teamno].pacers < a[teamno].spinners)
                        printf("Difference is %d\n",(a[teamno].spinners - a[teamno].pacers));
                        else
                        printf("Difference is 0\n");
            }

            printf("Enter K, the number of times player is declared Man of The match\n");
            int K; scanf("%d\n",&K);

            no_of_man=0;
            int ans[N]; for(int i=0;i<N;i++) ans[i]=-1;
            ijk=0;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    if(c[i].man_of_the_match==c[j].man_of_the_match)
                        no_of_man++;
                }
                if(no_of_man==K)
                {
                    ans[ijk]=c[i].man_of_the_match;
                    ijk++;
                }
            }
            ijk=0; int maxcent=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<15;j++)
                {
                    if(a[i].b[j].player_id==ans[ijk] && ans[ijk]!=-1)
                    {
                        if(a[i].b[j].century > maxcent)
                            maxcent = a[i].b[j].century;
                        ijk++;
                    }
                }
            }

            ijk=0;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<15;j++)
                {
                    if(a[i].b[j].player_id== ans[ijk] && a[i].b[j].century==maxcent)
                       {
                         printf("%d\n",a[i].b[j].player_id);
                         ijk++;
                       }

                }
            }




      /*  for(int i=0;i<n;i++)
        {
            printf("pre-final stats for team %d\n",i);
            for(int j=0;j<15;j++)
            {
            printf("Player ID -- %d\n", a[i].b[j].player_id);
            printf("Previous total score of player -- %d\n",a[i].b[j].previous_total_score);
            printf("Previous average of player -- %d\n",a[i].b[j].previous_avg);
            printf("Previous total wickets -- %d\n",a[i].b[j].previous_total_wickets);
            printf("Previous Wicket avg -- %d\n",a[i].b[j].previous_wicket_avg);
            printf("Player role -- %d\n\n\n",a[i].b[j].player_role);
            }
        }*/
}
