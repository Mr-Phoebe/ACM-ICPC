class Solution(object):
    def isRectangleCover(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: bool
        """
        def recordCorner(point):
            if point in corners:
                corners[point] += 1
            else:
                corners[point] = 1

        corners = {}
        area =  0
        left = min(x[0] for x in rectangles)
        bottom = min(x[1] for x in rectangles)
        right = max(x[2] for x in rectangles)
        top = max(x[3] for x in rectangles)

        for sub in rectangles:
            ax, ay, bx, by = sub[:]
            area += (bx-ax)*(by-ay)
            map(recordCorner, [(ax, ay), (bx, by), (ax, by), (bx, ay)])

        if area != (top-bottom)*(right-left): return False

        big_four = [(left,bottom),(right,top),(left,top),(right,bottom)]

        for bf in big_four:                         # check corners of big rectangle
            if bf not in corners or corners[bf] != 1:
                return False

        for key in corners:                         # check existing "inner" points
            if corners[key]%2 and key not in big_four:
                return False

        return True