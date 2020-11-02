package programmers.뉴스클러스터링;

import java.util.HashMap;
import java.util.Map;
import java.util.regex.Pattern;

import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String str1 = "FRANCE";
        String str2 = "french";

        int result = solution(str1, str2);

        System.out.println(result);
    }


    static int solution(String str1, String str2) {
        Map<String, Integer> totalMap = new HashMap<>();
        Map<String, Integer> intersectionMap = new HashMap<>();
        int answer = 0;
        int totalSize = 0;
        int intersectionSize = 0;
        int value = 0;

        str1 = str1.toUpperCase();
        str2 = str2.toUpperCase();

        Map<String, Integer> str1Map = multipleSets(str1);
        Map<String, Integer> str2Map = multipleSets(str2);

        if (str1Map.size() == 0 || str2Map.size() == 0) {
            return (str1.equals(str2) ? 1 : 0) * 65536;
        }

        for (String key : str1Map.keySet()) {
            totalMap.put(key, str1Map.get(key));
            if (str2Map.containsKey(key)) {
                value = str1Map.get(key) <= str2Map.get(key) ? str1Map.get(key) : str2Map.get(key);
                intersectionSize += value;
                intersectionMap.put(key, value);
            }
        }

        for (String key : str2Map.keySet()) {
            if (totalMap.containsKey(key)) {
                value = totalMap.get(key) >= str2Map.get(key) ? totalMap.get(key) : str2Map.get(key);
            } else {
                value = str2Map.get(key);
            }
            totalMap.put(key, value);
        }

        for(String key : totalMap.keySet()){
            totalSize += totalMap.get(key);
        }

        answer = (int) (((double) intersectionSize / (double) totalSize) * 65536);

        return answer;
    }


    static Map<String, Integer> multipleSets(String str) {
        Map<String, Integer> multipleMap = new HashMap<>();
        String currentKey;

        for (int i = 0; i < str.length() - 1; i++) {
            currentKey = str.substring(i, i + 2);
            if (!Pattern.matches("^[a-zA-Z]*", currentKey)) {
                continue;
            }
            if (multipleMap.containsKey(currentKey)) {
                multipleMap.put(currentKey, multipleMap.get(currentKey) + 1);
            } else {
                multipleMap.put(currentKey, 1);
            }
        }

        return multipleMap;
    }
}
