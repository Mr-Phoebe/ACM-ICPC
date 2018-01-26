object Solution {
    def lengthOfLastWord(input: String): Int = {
        val tmp = input.split("\\s+")
        if(tmp.length == 0)
            0
        else
            tmp.last.length
    }
}
