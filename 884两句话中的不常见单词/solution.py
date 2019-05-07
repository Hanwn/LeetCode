class Solution(object):
    def uncommonFromSentences(self, A, B):
        """
        :type A: str
        :type B: str
        :rtype: List[str]
        """
        res = []
        listA = A.split(' ')
        dic = {}
        listB = B.split(' ')
        for each in listA:
            dic[each] = 0
        for each in listB:
            dic[each] = 0
        for each in listA:
            dic[each] = dic[each] + 1
        for each in listB:
            dic[each] = dic[each] + 1
        for key,value in dic.items():
            if value == 1:
                res.append(key)
        return res
        
