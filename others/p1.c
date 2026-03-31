#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#define Max 80000
clock_t start,stop;/*clock_t is a built-in type for processor time (ticks)*/
double duration;/*records the run time (seconds) of a function*/
/*解法一：双循环*/
int* Sum1(int* nums, int numsSize, int target) {
    int i,j;
    for(i=0;i<numsSize;i++){
        for(j=i+1;j<numsSize;j++){/*遍历数组*/
            if(nums[i]+nums[j]==target){
                int* ret=(int *)malloc(sizeof(int)*2);
                ret[0]=nums[i];ret[1]=nums[j];
                return ret;/*返回数组下标*/
            }
        }
    }
    return NULL;/*若没有，返回NULL*/
}
/*解法二：先排序后双向*/
/*分治思想，归并排序*/
void Merge(int* arr, int left, int right, int* temp){
    if (left >= right)
    	return;/*递归出口*/
	int mid = (left + right) / 2;
	Merge(arr, left, mid, temp);       /*左*/
	Merge(arr, mid + 1, right, temp);	/*右*/
    //合并
	int begin1 = left, end1 = mid;			/*左*/
	int begin2 = mid + 1, end2 = right;		/*右*/
	int i = begin1;

    //排序两个有序数组
	while (begin1 <= end1 && begin2 <= end2){
		if (arr[begin1] <= arr[begin2]){
			temp[i] = arr[begin1];
			begin1++;
		}
		else{
			temp[i] = arr[begin2];
			begin2++;
		}
		i++;
	}
    /*不同时完成情况*/
	while (begin1 <= end1){
		temp[i] = arr[begin1];
		begin1++;
		i++;
	}

	while (begin2 <= end2){
		temp[i] = arr[begin2];
		begin2++;
		i++;
	}
	for (i = left; i <= right; i++){
		arr[i] = temp[i];/*临时数组到原数组*/
	}
}
int * Sum2(int *nums, int numsSize, int target){
    int temp[numsSize];
    Merge(nums,0,numsSize-1,temp);/*对数组进行排序处理*/
    int i,j;
    i=0;j=numsSize-1;/*从两侧同时向结果逼近*/
    while(i<j){
        if(nums[i]+nums[j]==target){
            int *ret=(int *)malloc(sizeof(int)*2);
            ret[0]=nums[i];ret[1]=nums[j];
            return ret;
        }
        else if(nums[i]+nums[j]>target)
            j--;
        else 
            i++;/*若结果大，则大者减小，反之小者增大*/
    }
    return NULL;
}

int main(){
    srand(time(0));
    int N,V,c,i;
    V=N=Max;/*按题目要求，对VN赋相同初始值*/
    int S[Max],* anwser;
    for(i=0;i<N;i++){
        S[i]=rand()%V;
    }/*对数组赋初始值*/
    c=rand()%(2*V);
    start=clock();/*records the ticks at the beginning of the function call*/
    #if 1
    for(int k=0;k<100;k++)
        anwser=Sum1(S,N,c);/*my function*/
    #else
    for(int k=0;k<100;k++)
        anwser=Sum2(S,N,c);
    #endif 
    stop=clock();/*records the ticks at the end of the function call*/
    printf("tick=%d\n",(int)stop-start);
    duration=((double)(stop-start))/CLK_TCK;
    /*CLK_TCK is a built-in constant = ticks per second*/
    printf("duration=%lf\n",duration);
    return 0;
}
