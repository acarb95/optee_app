policy_version = 1
remote_server = "10.0.0.2:3490"

log_open = true
log_close = true

policy_result = POLICY_ALLOW
comment = ""

function evaluate_policy( op )

	if op == POLICY_OP_OPEN then
		policy_result = POLICY_ALLOW
	elseif op == POLICY_OP_CLOSE then
		policy_result = POLICY_NOT_ALLOW
	else
		policy_result = POLICY_ERROR_UNKNOWN_OP
	end 

end

----
location: Vancouver, BC
----
Sun Apr 22 21:28:26 2018 - CREATED bio [ location: Vancouver, BC ]
----
Name: Peter Chen
Age: 25
Gender: Male
Address: 1234 High Park Avenue, Baltimore, MD
Occupation: Student
Blood Type: A+
Illness: none
