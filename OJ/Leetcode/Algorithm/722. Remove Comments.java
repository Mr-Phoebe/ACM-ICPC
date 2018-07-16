class Solution {
    private boolean normal;
    private String prev;
    List<String> ans = new ArrayList<>();

     private void add(String line)
     {
        prev = "";
        if(line.length() != 0)
            ans.add(line);
    }

    private void incomment(String line) {
        int p1 = line.indexOf("*/");
        if(p1 == -1)    return;
        normal = true;
        outcomment(line.substring(p1+2));
    }

    private void outcomment(String line) {
        int p1 = line.indexOf("/*");
        int p2 = line.indexOf("//");
        if(p1 == -1 && p2 == -1)
        {
            add(prev + line);
        }
        else if(p2 != -1 && (p1 == -1 || p1 > p2))
        {
            add(prev + line.substring(0, p2));
        }
        else
        {
            prev += line.substring(0, p1);
            normal = false;
            incomment(line.substring(p1+2));
        }
    }

    public List<String> removeComments(String[] source) {
        normal = true;
        prev = "";
        for(String line : source)
        {
            if(normal)
                outcomment(line);
            else
                incomment(line);
        }
        return ans;
    }
}
