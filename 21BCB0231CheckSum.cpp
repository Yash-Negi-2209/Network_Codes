#include <bits/stdc++.h>
using namespace std;
string one_complement(string data)
{
for (int i = 0; i < data.length(); i++)
{
if (data[i] == '0')
data[i] = '1';
else
data[i] = '0';
}
return data;
}
string checkSum(string data, int block_size)
{
int n = data.length();
if (n % block_size != 0)
{
int pad_size = block_size - (n % block_size);
for (int i = 0; i < pad_size; i++)
{
data = '0' + data;
}
}
string result = "";
for (int i = 0; i < block_size; i++)
{
result += data[i];
}
for (int i = block_size; i < n; i += block_size)
{
string next_block = "";
for (int j = i; j < i + block_size; j++)
{
next_block += data[j];
}
string checkadd = "";
int sum = 0, carry = 0;
for (int k = block_size - 1; k >= 0; k--)
{
sum += (next_block[k] - '0') + (result[k] - '0');
carry = sum / 2;
if (sum == 0)
{
checkadd = '0' + checkadd;
sum = carry;
}
else if (sum == 1)
{
checkadd = '1' + checkadd;
sum = carry;
}
else if (sum == 2)
{
checkadd = '0' + checkadd;
sum = carry;
}
else
{
checkadd = '1' + checkadd;
sum = carry;
}
}
string final_chek = "";
if (carry == 1)
{
for (int l = checkadd.length() - 1; l >= 0;
l--)
{
if (carry == 0)
{
final_chek = checkadd[l] + final_chek;
}
else if (((checkadd[l] - '0') + carry) % 2 == 0)
{
final_chek = "0" + final_chek;
carry = 1;
}
else
{
final_chek = "1" + final_chek;
carry = 0;
}
}
result = final_chek;
}
else
{
result = checkadd;
}
}
cout << "The Checksum value is:" + result << endl;
return one_complement(result);
}
bool checker(string sender_msg,
string reciever_msg,
int block_size)
{
cout << "On sender's side:";
string sender_checksum = checkSum(sender_msg, block_size);
cout << "On reciever's side:";
string receiver_checksum = checkSum(
reciever_msg + sender_checksum, block_size);
if (count(receiver_checksum.begin(), receiver_checksum.end(), '0') == block_size)
{
return true;
}
else
{
return false;
}
}
int main()
{
string sender_msg = "1011001000110001";
string recv_message = "1011001000110001";
int block_size = 4;
if (checker(sender_msg,
recv_message,
block_size))
{
cout << "There was no error in the transmission.";
}
else
{
cout << "There was error in the transmission.";
}
return 0;
}