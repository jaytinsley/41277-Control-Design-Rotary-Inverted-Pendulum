%% 41277 Control Design
%  Teensy 4.1 - Save test data
%
%  This script will run after sttoping the Simulink Model. 


%% save data.
file_name = "Teensy41_test_data";
count = 1;

check_file = true;
while(check_file)
    if count<10
        file_full = file_name + "_0" + num2str(count) + ".mat";    
    else
        file_full = file_name + "_" + num2str(count) + ".mat";   
    end
    if  (exist(file_full,'file')>0)
        count = count + 1;     
    else 
        check_file = false;
    end
end
save(file_full,'logsout');


