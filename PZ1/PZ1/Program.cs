using System;
using System.Collections.Generic;
using System.IO;
using System.Globalization;

namespace PZ1
{
    class Program
    {
        static void Main(string[] args)
        {
            string head = string.Format("|{0, -15}|{1, -15}|{2, -15}|{3, -15}|{4, -15}|{5, -15}|", "Фамилия", "Имя", "Отчество", "Вес", "Дата рождения", "Возраст");
            var list = new List<Person>();
            var in_lines = File.ReadAllLines("in.txt");

            foreach (var line in in_lines)
            {
                string[] data = line.Split(' ');
                list.Add(new Person(data[1], data[2], data[0], Convert.ToDouble(data[3]), DateTime.ParseExact(data[4], "MM-dd-yyyy", CultureInfo.InvariantCulture)));
            }

            Console.WriteLine("Выберите порядок сортировки сортировки:\n 1 - по возрастанию\n 2 - по убыванию");
            int flag = int.Parse(Console.ReadLine());
            if (flag == 1)
            {
                list.Sort((x, y) => y.Age.CompareTo(x.Age));
            }
            else
            {
                list.Sort((x, y) => x.Age.CompareTo(y.Age));
            }

            using (StreamWriter ouFile = new StreamWriter(File.OpenWrite("ou.txt")))
            {
                ouFile.WriteLine(head);
                foreach (var person in list)
                    ouFile.WriteLine(person.Info());
            }
        }
    }
    class Person
    {
        string firstname, lastname, middlename;
        double weight;
        DateTime birthday;
        public Person(string Firstname, string Middlename, string Lastname, double Weight, DateTime Birthday)
        {
            firstname = Firstname;
            lastname = Lastname;
            middlename = Middlename;
            weight = Weight;
            birthday = Birthday;
        }
        public int Age
        {
            get
            {
                return DateTime.Now.Year - birthday.Year - (DateTime.Now.DayOfYear < birthday.DayOfYear ? 1 : 0);
            }
        }
        public string Info()
        {
            string info = string.Format("|{0, -15}|{1, -15}|{2, -15}|{3, -15}|{4, -15}|{5, -15}|", lastname, firstname, middlename, weight.ToString("N2"), birthday.ToString("MM-dd-yyyy"), Age);
            return info;
        }
    }
}
