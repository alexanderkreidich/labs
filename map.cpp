#include <iostream>
#include <map>
using namespace std;

int main() {
    
    string text = "Hello, world! This is a test world. My World goodbye World";
    
    map<string, int> wordCount;
    int totalWords = 0;
    string word = "";
    
    // Проходим по каждому символу текста
    for (int i = 0; i <= text.size(); i++) {

        char c = (i < text.size() ? text[i] : ' '); // На конце добавляем пробел, чтобы слово обработалось

        if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9')) {
            if (c >= 'A' && c <= 'Z') {
                c = c - 'A' + 'a';
            }
            word.push_back(c);
        } else {
            // Если встретился пробел, знак препинания и слово не пустое, сохраняем слово
            if (!word.empty()) {
                wordCount[word]++;
                totalWords++;
                word = ""; 
            }
        }
    }

    //Итерация по контейнеру map
    for (map<string, int>::iterator it = wordCount.begin(); it != wordCount.end(); ++it) {
        double percent = (it->second * 100.0) / totalWords;
        cout << it->first << ": " << percent << "% (" 
             << it->second << "/" << totalWords << ")" << endl;
    }
    
    return 0;
}
