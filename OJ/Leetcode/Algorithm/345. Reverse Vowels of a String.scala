object Solution {
    def reverseVowels(input: String): String = {
        if (input == null || input.isEmpty)
            input
        else {
            val vowel_list = "aeiouAEIOU"
            val arr = input.toCharArray

            var begin = 0
            var end = arr.length - 1
            while (begin <= end) {
                while (begin <= end && !vowel_list.contains(arr(begin)))
                    begin += 1
                while (begin <= end && !vowel_list.contains(arr(end)))
                    end -= 1
                if (begin <= end) {
                    var temp = arr(begin)
                    arr(begin) = arr(end)
                    arr(end) = temp
                }
                begin += 1
                end -= 1
            }
            arr.mkString("")
        }
    }
}
