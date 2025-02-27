class Solution:
    def lenLongestFibSubseq(self, arr: List[int]) -> int:
        hash_set=set(arr)
        max_len=0
        for i in range(0,len(arr)):
            for j in range(i+1,len(arr)):
                a = arr[i]
                b = arr[j]
                c=a+b
                count=2
                while c in hash_set:
                    a=b
                    b=c
                    c=a+b
                    count+=1
                max_len=max(max_len,count)
        return max_len if max_len>=3 else 0


        