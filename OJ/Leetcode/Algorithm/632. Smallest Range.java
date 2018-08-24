
public int[] smallestRange(int[][] nums) {
		PriorityQueue<Element> pq = new PriorityQueue<Element>(new Comparator<Element>() {
			public int compare(Element a, Element b) {
				return a.val - b.val;
			}
		});
		int min = Integer.MAX_VALUE, max = Integer.MIN_VALUE;
		for (int i = 0; i < nums.length; i++) {
			Element e = new Element(i, 0, nums[i][0]);
			pq.offer(e);
			max = Math.max(max, nums[i][0]);
		}
		int range = Integer.MAX_VALUE;
		int start = -1, end = -1;
		while (pq.size() == nums.length) {

			Element curr = pq.poll();
			if (max - curr.val < range) {
				range = max - curr.val;
				start = curr.val;
				end = max;
			}
			if (curr.idx + 1 < nums[curr.row].length) {
				curr.idx = curr.idx + 1;
				curr.val = nums[curr.row][curr.idx];
				pq.offer(curr);
				if (curr.val > max) {
					max = curr.val;
				}
			}
		}

		return new int[] { start, end };
	}

	class Element {
		int val;
		int idx;
		int row;

		public Element(int r, int i, int v) {
			val = v;
			idx = i;
			row = r;
		}
	}

