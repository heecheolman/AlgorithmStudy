package programmers.카카오코딩테스트.오픈채팅방;

import java.util.*;

public class Solution {
    /*
Enter uid1234 Muzi
Enter uid4567 Prodo
Leave uid1234
Enter uid1234 Prodo
Change uid4567 Ryan
    * */
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        String[] request = new String[5];
        for (int i = 0; i < 5; i++) {
            request[i] = sc.nextLine();
        }

        String[] result = solution(request);

        for (String text : result) {
            System.out.println(text);
        }
    }

    public static String[] solution(String[] record) {
        String[] answer;

        Map<String, String> nicknameMap = new HashMap<>();
        List<Map<String, String>> chatting = new ArrayList<>();

        for (String request : record) {
            String[] requestArray = request.split(" ");

            String action = requestArray[0];
            String uid = requestArray[1];
            String nickname;

            switch (action) {
                case "Enter":
                    // 채팅 로우 추가
                    addChattingRow(requestArray, chatting);
                    // uid - nickname 데이터 추가
                    nickname = requestArray[2];
                    nicknameMap.put(uid,nickname);
                    break;
                case "Leave":
                    // 채팅 로우 추가
                    addChattingRow(requestArray, chatting);
                    break;
                case "Change":
                    // uid - nickname 데이터 추가
                    nickname = requestArray[2];
                    nicknameMap.put(uid, nickname);
                    break;
            }
        }

        // List to Array
        answer = new String[chatting.size()];
        for (int i = 0; i < chatting.size(); i++) {
            Map<String, String> row = chatting.get(i);

            String nickname = nicknameMap.get(row.get("uid"));
            String actionText = "Enter".equals(row.get("action")) ? "님이 들어왔습니다." :"님이 나갔습니다.";

            answer[i] = nickname + actionText;
        }

        return answer;
    }

    public static void addChattingRow(String[] requestArray, List<Map<String, String>> chatting) {
        Map<String, String> row = new HashMap<>();
        String action = requestArray[0];
        String uid = requestArray[1];
        row.put("uid", uid);
        row.put("action", action);
        chatting.add(row);
    }
}
