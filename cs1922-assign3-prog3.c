#include "header.h" 

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("error: No files entered\n");
        exit(0);
    }
    int s_length,temp;
    int no_of_trans = argc - 1;
    s_length = find_schedule_length(argc, argv);
    NODE schdl[s_length + 1];
    build_schdl(argc, argv, schdl, s_length);
    int adj_mat[no_of_trans][no_of_trans];
    memset(adj_mat, temp, sizeof(adj_mat));
    for (int i = 1; i <= s_length; i++)
    {
        if (!strcmp(schdl[i].cmd, "read") || !strcmp(schdl[i].cmd, "write"))
        {
            for (int j = i + 1; j <= s_length; j++)
            {
                if (is_edgeExist("write", "read"))
                    putEdge;
                if (is_edgeExist("read", "write"))
                    putEdge;
                if (is_edgeExist("write", "write"))
                    putEdge;
            }
        }
    }
    int power[no_of_trans][no_of_trans]; 
    int temp_m[no_of_trans][no_of_trans];
    for (int p = 1; p <= no_of_trans; p++)
    {
        if (p == 1) 
        {
            for (int i = 0; i < no_of_trans; i++)
                for (int j = 0; j < no_of_trans; j++)
                    power[i][j] = adj_mat[i][j];
        }
        else
        {
            for (int i = 0; i < no_of_trans; i++)
            {
                for (int j = 0; j < no_of_trans; j++)
                {
                    temp_m[i][j] = 0;
                    for (int k = 0; k < no_of_trans; k++)
                    {
                        temp_m[i][j] += power[i][k] * adj_mat[k][j];
                    }
                }
            }
            for (int i = 0; i < no_of_trans; i++)
            {
                for (int j = 0; j < no_of_trans; j++)
                {
                    power[i][j] = temp_m[i][j]; 
                    if (i == j && power[i][i] != 0)
                    {
                        printf("Not Conflict Serializable\n");
                        for (int i = 1; i <= s_length; i++)
                            free(schdl[i].cmd);
                        return 0;
                    }
                }
            }
        }
    }
    printf("Conflict Serializable\n");
    for (int i = 1; i <= s_length; i++)
        free(schdl[i].cmd);
    return 0;
}
