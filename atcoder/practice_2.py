'''
1. 二分查找插入
2. 对于5个球来说，单独处理，达到理论下界log(n!)/log2
'''
import sys
def letter(num):
	    return chr(ord('A')+num)

	    def compare(a, b):
		        if comp[a][b] != 0:
			        return comp[a][b]
			           print("? %s %s" % (letter(a), letter(b)))
				       sys.stdout.flush()
	    res = input()
	    if res == '<':
	            comp[a][b] = -1
		            comp[b][a] = 1
			            return -1
				        else:
					        comp[a][b] = 1
						        comp[b][a] = -1
							        return 1

								def bmerge(a, b):
									    l = 0
									        r = len(a)
									        while l < r:
									            mid = int((l+r) / 2)
									            res = compare(a[mid], b)
									            if res < 0:
									                l = mid + 1
									            else:
									                r = mid
									        a.insert(r, b)

									    arr = []
									    comp = [[0]*26 for i in range(26)]
									    N, Q = map(int, input().split())

	result = [0]
	if N == 5:
	    a1 = [0]
	        a2 = [2]
		    bmerge(a1, 1)
	    bmerge(a2, 3)
	    if compare(a1[0], a2[0]) < 0:
	            a2.insert(0, a1[0])
	        a3 = a2
		        rest = a1[1]
			    else:
			            a1.insert(0, a2[0])
	        a3 = a1
		        rest = a2[1]
			    bmerge(a3, 4)
	    a4 = a3[1:]
	        bmerge(a4, rest)
	    a4.insert(0, a3[0])
	    result = a4
	    else: 
	        for i in range(1, N):
			        bmerge(result, i)

				print("! ",end='')
				for i in range(len(result)):
					    print(letter(result[i]), end='')
					    print()
					    sys.stdout.flush()
