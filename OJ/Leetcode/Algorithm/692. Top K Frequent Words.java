class Solution {
    class Tuple implements Comparable<Tuple>
    {
        String word;
        int freq;

        public Tuple(String word, int freq)
        {
            this.word = word;
            this.freq = freq;
        }
        @Override
        public int compareTo(Tuple b)
        {
            if(b.freq == this.freq)
                return this.word.compareTo(b.word);
            return b.freq - this.freq;
        }
    }
    public List<String> topKFrequent(String[] words, int k) {
        HashMap<String, Integer> cnt = new HashMap<>();
        List<String> ans = new ArrayList();
        Queue<Tuple> pq = new PriorityQueue<>();

        for(String str : words)
            cnt.put(str, cnt.getOrDefault(str, 0) + 1);

        Iterator it = cnt.keySet().iterator();
        while(it.hasNext())
        {
            String str = it.next().toString();
            pq.add(new Tuple(str, cnt.get(str)));
        }

        while(true && k > 0)
        {
            Tuple pair = pq.poll();
            if(pair == null)
                break;
            ans.add(pair.word);
            k -= 1;
        }
        return ans;
    }
}
