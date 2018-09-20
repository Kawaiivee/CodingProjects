class Student
#Init
    @@id = 0
    def initialize(name)
        @name = name
        @password = ""
        @id = @@id = @@id + 1
    end

#Name
    def name
        @name
    end

    def name=(name)
        @name = name
    end

#Id - no mutatator as there is a counter for each id
    def id
        @id
    end

#Password
    def password
        @password
    end

    def password=(password)
        @password = password
    end
#toString
    def toString
        idSTR = @id.to_s
        return "Name: "+@name+"\nID: "+idSTR+"\nPassword: "+@password
    end
end

S1 = Student.new("Mario")
S2 = Student.new("Luigi")
S3 = Student.new("Yoshi")

puts S1.toString
puts S2.toString
puts S3.toString
