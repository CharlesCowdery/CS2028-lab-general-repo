#include <iostream>
#include <fstream>
#include "BinaryTree.h"
#include <random>

void readWordsFromFile(const std::string& filename, BinaryTree<Word>& tree) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return;
    }

    std::string word;
    while (file >> word) {
        Word w(word);
        try {
            Node<Word>* existing = tree.find(w);
            if (existing)
                existing->data.inc();
            else
                tree.insert(w);
        }
        catch (repeatValue& e) {
            std::cerr << e.what() << ": " << word << std::endl;
        }
    }
    file.close();
}

void displayMenu() {
    std::cout << "1. Search for a word\n"
        << "2. List all words in ascending order\n"
        << "3. List all words in descending order\n"
        << "4. Get size of the tree\n"
        << "5. Remove a word\n"
        << "6. Empty the tree\n"
        << "7. Exit\n"
        << "Enter your choice: ";
}

int main(){
    BinaryTree<int> nums;

    //test
    for (int i = 0; i < 1000;i++) {
        int k = rand() % 1000;
        //std::cout << "inserting " << k ;
        try {
            nums.insert(k);
        }
        catch (std::exception e) {

        }
        std::cout << " " << std::endl;
    }

    BinaryTree<Word> tree;

    std::string filename = "input.txt"; // Change this to your input file name
    readWordsFromFile(filename, tree);

    int choice;
    std::string word;
    while (true) {
        displayMenu();
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter word to search: ";
            std::cin >> word;
            {
                Word w(word);
                Node<Word>* found = tree.find(w);
                if (found)
                    std::cout << "Frequency of " << word << ": " << found->data.count << std::endl;
                else
                    std::cout << word << " not found in the tree." << std::endl;
            }
            break;
        case 2: {
            Node<Word>** ascArr = tree.getAllAscending();
            for (int i = 0; i < tree.size(); ++i) {
                std::cout << ascArr[i]->data.word << " (" << ascArr[i]->data.count << "," << tree.nodeHeight(ascArr[i]) << "," << tree.bf(ascArr[i]) << "), ";
            }
            std::cout << std::endl;
            free(ascArr);
            break;
        }
        case 3: {
            Node<Word>** descArr = tree.getAllDescending();
            for (int i = 0; i < tree.size(); ++i) {
                std::cout << descArr[i]->data.word << " (" << descArr[i]->data.count << "," << tree.nodeHeight(descArr[i]) << "," << tree.bf(descArr[i]) << "), ";
            }
            std::cout << std::endl;
            free(descArr);
            break;
        }
        case 4:
            std::cout << "Size of the tree: " << tree.size() << std::endl;
            break;
        case 5:
            std::cout << "Enter word to remove: ";
            std::cin >> word;
            {
                Word w(word);
                Node<Word>* removed = tree.remove(w);
                if (removed)
                    std::cout << word << " removed from the tree." << std::endl;
                else
                    std::cout << word << " not found in the tree." << std::endl;
            }
            break;
        case 6:
            tree.emptyTree();
            std::cout << "Tree emptied." << std::endl;
            break;
        case 7:
            std::cout << "Exiting program." << std::endl;
            return 0;
        default:
            std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }

    return 0;

    BinaryTree<int> t = BinaryTree<int>();
    t.insert(7);
    t.insert(6);
    t.insert(5);
    t.insert(4);
    t.insert(3);
    t.insert(2);
    t.insert(1);
    t.rebalance(&t.root);
    t.insert(8);
    return 0;
}

