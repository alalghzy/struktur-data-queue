#include <iostream>
#define MAX_QUEUE_SIZE 5 // Maksimum data queue

using namespace std;

class Queue {
private:
    int front, rear, data[MAX_QUEUE_SIZE];

public:
    Queue() {
        front = 0;
        rear = 0;
    }

    bool isFull() {
        return rear == MAX_QUEUE_SIZE;
    }

    bool isEmpty() {
        return rear == 0;
    }

    void printQueue() {
        if (isEmpty()) {
            cout << "Antrian kosong" << endl;
        } else {
            cout << "QUEUE: ";
            for (int i = front; i < rear; i++) {
                cout << data[i] << ((rear - 1 == i) ? "" : ",");
            }
            cout << endl;
        }
    }

    void enqueue() {
        if (isFull()) {
            cout << "Antrian penuh!" << endl;
        } else {
            int inputData;
            cout << "Masukkan Data: ";
            cin >> inputData;
            data[rear] = inputData;
            rear++;
            cout << "Data ditambahkan" << endl;
            printQueue();
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Antrian masih kosong" << endl;
        } else {
            cout << "Mengambil data \"" << data[front] << "\"..." << endl;
            for (int i = front; i < rear; i++) {
                data[i] = data[i + 1];
            }
            rear--;
            printQueue();
        }
    }
};

int main() {
    Queue q;
    int choice;

    do {
        cout << "-------------------\n"
             << "   Menu Pilihan\n"
             << "-------------------\n"
             << " [1] Menambahkan Data (Enqueue)\n"
             << " [2] Mengambil Data (Dequeue)\n"
             << " [3] Keluar\n\n"
             << "-------------------\n"
             << "Masukkan pilihan: ";
        cin >> choice;

        switch (choice) {
            case 1:
                q.enqueue();
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                cout << "Terima kasih telah menggunakan program ini." << endl;
                break;
            default:
                cout << "Pilihan tidak tersedia" << endl;
                break;
        }
    } while (choice != 3);

    return 0;
}
