TASK 1 – Understand the Problem and Identify the Objects
1. Problem overview
The Namma Metro Smart-Card Fare System divides the metro network into three zones: Inner, Middle and Outer. The basic fares are Rs 10, Rs 20 and Rs 30 respectively, according to the farthest zone travelled.
A 20% surcharge is added during peak hours:
Morning peak: 8:00 AM to before 10:00 AM
Evening peak: 5:00 PM to before 8:00 PM
A passenger can travel only when at least Rs 50 remains on the smart card after the fare is deducted. The fare and balance should be stored in integer paise to avoid floating-point rounding errors.
Assumption: The assignment says that students and senior citizens receive a concession, but it does not specify the concession percentage or exact calculation rule. Therefore, this analysis does not invent a concession rate. It identifies concession handling as a rule that must be added when the metro authority supplies the rate.
2. Objects, data and behaviour
Object
Data (attributes)
Behaviour (methods/responsibilities)
Why it is needed
Passenger
Name, passenger category (general/student/senior citizen)
Provide passenger details and identify the applicable concession category
Different passenger categories may receive concessions.
SmartCard
Card number, balance in paise, minimum required remaining balance
Check whether travel is allowed, deduct fare, display balance, reject an invalid deduction
It protects the stored balance and prevents a journey that would leave less than Rs 50.
Journey
Source/destination or farthest zone, travel time, peak/off-peak status
Identify the zone travelled and request the correct fare
Each journey has its own zone and travel time.
Zone
Inner, Middle, Outer
Represent the valid metro fare zones
A named zone type is safer and clearer than unexplained numeric values.
FareTable
Base fares and surcharge percentage
Return the base fare for a zone and apply the peak surcharge
Fare values are kept in one place, so a fare revision is easier.
3. Procedural programming and object-oriented programming
Procedural approach
A procedural program could store values in separate variables and use free functions, for example:
long long balance = 10000;
long long calculateFare(int zone, bool peak);
bool canTravel(long long balance, long long fare);
void deductFare(long long& balance, long long fare);
The functions operate on data passed to them. If many functions can directly change balance, it becomes easier to accidentally break the minimum-balance rule.
Object-oriented approach
An object-oriented program groups related data and behaviour into classes:
SmartCard stores its balance privately and controls deductions.
Journey stores journey details and calculates the fare.
FareTable stores the fare rules in one place.
Passenger stores passenger information and category.
This design keeps related responsibilities together. For example, other parts of the program cannot directly change a private smart-card balance; they must use the class's checked methods.
4. Four basic OOP principles in this system
Encapsulation: Keep SmartCard::balance private. Update it only through a method such as deduct() after checking canTravel().
Abstraction: The main program can call journey.calculateFare() without needing to know every internal fare-calculation step.
Inheritance: A general Passenger class could be a base class, with StudentPassenger and SeniorCitizenPassenger as derived classes if their concession rules differ.
Polymorphism: A virtual method such as getConcessionPercent() could be overridden by the student and senior-citizen classes. The actual percentages must come from the metro's official rules; they are not specified in this assignment.
5. Rules every valid journey must satisfy
The zone must be one of Inner, Middle or Outer (until the design is extended).
Base fares are Rs 10, Rs 20 and Rs 30 for Inner, Middle and Outer.
Apply a 20% surcharge during 8:00–9:59 AM and 5:00–7:59 PM. Thus, exactly 10:00 AM and exactly 8:00 PM are off-peak.
Store money as integer paise: Rs 10 = 1000 paise.
Allow a journey only when balance - fare >= 5000 paise (Rs 50).
Never deduct a fare if the journey is denied.
The balance must never become negative.
Apply a student or senior-citizen concession only after its official rate and order of application have been specified.
6. Alternative concept and complexity analysis
If the system used global variables and free functions instead of SmartCard, Journey and FareTable classes:
The fare calculation would still take O(1) time for one journey because it uses a fixed number of comparisons and arithmetic operations.
The memory required to store one card balance would still be O(1) per card.
The object-oriented version groups the balance and its validation rules inside SmartCard. In a procedural version, every function that changes the global balance must follow the same rule.
If a fare changes, a central fare table or fare-calculation function can be updated. If fare values are repeated in many procedural functions, more places may need editing, increasing the chance of inconsistent values.
Comparison
Procedural style
Object-oriented style
Data organisation
Separate variables
Data grouped in objects
Behaviour
Free functions
Class methods
Balance protection
Depends on every function following the rule
Private balance and checked methods enforce the rule at the class boundary
Time per journey
O(1)
O(1)
Space per card
O(1)
O(1)
Maintenance
Can become harder as related data and functions spread
Related data and behaviour are grouped together
7. Conclusion
An object-oriented design is suitable for the metro smart-card system because passengers, journeys, fare rules and smart cards have separate responsibilities. Keeping the smart-card balance private and storing money in integer paise helps protect the minimum-balance rule and avoids floating-point fare errors. The design can be extended for new zones and concession rules when the exact requirements are known.