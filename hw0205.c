#include<stdio.h>
#include<stdint.h>

int main(){

    int32_t width=0,height=0,panes=0,command=-1;

    printf("please input the window size (width)x(height): ");
    if(scanf("%dx%d", &width, &height)!=2){
        printf("error\n");
        return 0;
    }

    printf("please input the total pane number: ");
    if(scanf("%d", &panes)!=1){
        printf("error\n");
        return 0;
    }

    printf("please input the pane for the job (0=all,-1=none):");
    if(scanf("%d", &command)!=1){
        printf("error\n");
        return 0;
    }

    int32_t square=1,row=0,col=0;
    while(square*square<panes)
        square++;
    square--;
    col=square;row=square;

    panes-=square*square;

    while(panes>col){
        col++;
        panes-=row;
    }
    //per shell height
    int32_t shell_height;
    int32_t extra_hei;
    if(panes) row++;

    height--;
    shell_height=height/row;
    extra_hei=height%row;

    //per width
    int32_t shell_width=width/col;
    int32_t extra_width=width%col;

    //1
    for(int32_t x=1;x<=row-1;x++){
        int temp_height=shell_height;
        if(extra_hei>0){
            temp_height++;
            extra_hei--;
        }
        for(int32_t i=1;i<=temp_height;i++){
            int32_t exw = extra_width; 
            int32_t cur_wid=0;

            for(int32_t y=1;y<=col;y++){
                int32_t temp_width=shell_width;

                if(exw){
                    temp_width++;
                    exw--;
                }

                for(int32_t j=1;j<=temp_width;j++){  
                    if(x==row-1 && i==temp_height)  break;           
                    cur_wid++;
                    if(i%temp_height==1 && j%temp_width==1){
                        printf("$");
                    }else if(i%temp_height==0 && j%temp_width==0 && cur_wid!=width && x!=row){
                        printf("┼");

                    }else if(i%temp_height==0 && x!=row){
                        printf("─");
                    }else if(j==temp_width && cur_wid!=width){
                        printf("│");

                    }else   printf(" ");
                    
                    
                }
            }
            if(x==row-1 && i==temp_height)   break; 
            printf("\n");


        }
    }
    //string
    int32_t cur_wid=0;
    int32_t exw = extra_width; 
    int32_t all=0;
    int32_t str_pane=panes;
    for(int32_t y=1;y<=col-1;y++){
        str_pane--;
        int32_t temp_width=shell_width;   
        if(exw){
            temp_width++;
            exw--;
        }
        for(int32_t j=1;j<=temp_width;j++){   
            cur_wid++;
            all++;
            if(j%temp_width==0 && cur_wid!=width){
                if(str_pane>0)
                    printf("┼");
                else
                    printf("┴");
            }else{
                printf("─");
                
            }
        }
    }
    if(panes)
        for(int32_t i=1;i<=width-all;i++)
                printf("─");
         
    printf("\n");

    //downer
    
    for(int32_t i=1;i<=shell_height;i++){
        int32_t exw = extra_width; 
        int32_t cur_wid=0;
        int32_t cur_pane=panes;
        for(int y=1;y<=panes;y++){
            int32_t temp_width=shell_width;   
            cur_pane--;
            if(exw){
                temp_width++;
                exw--;
            }
            for(int32_t j=1;j<=temp_width;j++){   
                cur_wid++;
                if(i%shell_height==1 && j%temp_width==1){
                    printf("$");
                }else if(i%shell_height==0 && j%temp_width==0 && cur_wid!=width && i!=shell_height){
                    printf("┼");

                }else if(i%shell_height==0 && i!=shell_height){
                    printf("─");
                }else if(j==temp_width && cur_wid!=width && cur_pane!=0){
                    printf("│");

                }else   printf(" ");
                    
                    
            }
        }

        printf("\n");
    }
    
    printf("\033[48;2;0;255;0m[0] 0:bash*\033[0m\n"); return 0;
}

