#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#define is_edgeExist(a, b) schdl[i].trans_num != schdl[j].trans_num && \
                               !strcmp(schdl[i].cmd, a) &&                \
                               !strcmp(schdl[j].cmd, b) &&                \
                               !strcmp(schdl[i].var, schdl[j].var)

#define putEdge adj_mat[schdl[i].trans_num - 1][schdl[j].trans_num - 1] = 1

#define err_msg(x) \
    {              \
        perror(x); \
        exit(0);   \
    }


typedef struct nodes 
{
    int trans_num; 
    char *cmd;     
    char *var;    
} NODE;

void to_low(char string[]);                     
int find_schedule_length(int, char *[]);       
int build_schedule(int, char *[], NODE *, int); 
void to_low(char string[])
{
    int i = 0;
    while (string[i])
    {
        string[i] = tolower(string[i]);
        i++;
    }
}
int find_schedule_length(int t, char *ptr[])
{
    int length = 0;
    int temp;
    for (int i = 1; i < t; i++)
    {
        FILE *fp;
        fp = fopen(ptr[i], "r");
        if (!fp)
            err_msg("error");
        fscanf(fp, "%d", &temp);
        length = length + temp;
        fclose(fp);
    }

    return length;
}

int build_schdl(int t, char *ptr[], NODE *sdl, int total_len)
{
    FILE *fp;
    int len;
    int sl_num;
    char *str;
    char *cmd;
    char *var;
    for (int i = 1; i < t; i++)
    {
        fp = fopen(ptr[i], "r");
        fscanf(fp, "%d", &len);
        for (int j = 1; j <= len; j++)
        {
            fscanf(fp, "%d %m[^\n\r]", &sl_num, &str);
            if (sl_num > total_len)
                err_msg("err:Invalid Inputs"); // error in case of invalid serial number
            if (str == NULL)
                str = " ";
            cmd = strtok_r(str, "(", &str);
            to_low(cmd);
            if (!strcmp(cmd, "read") || !strcmp(cmd, "write"))
                var = strtok_r(str, ")", &str);
            else
                var = "0";
            sdl[sl_num] = (NODE){i, cmd, var}; //Assign values to schedule
        }
        fclose(fp);
    }
    return 1;
}
