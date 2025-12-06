clear;


load("t1_stats.csv")
load("t1s_stats.csv")

%height the ball is dropped from
drop_height = t1_stats(:, 1);
infeasibilities = t1_stats(:, 2);
sucessful_catches = t1_stats(:, 3);
collisions = t1_stats(:, 4);
agent_effort = t1_stats(:, 5);

drop_height_s = t1s_stats(:, 1);
infeasibilities_s = t1s_stats(:, 2);
sucessful_catches_s = t1s_stats(:, 3);
collisions_s = t1s_stats(:, 4);
agent_effort_s = t1s_stats(:, 5);

figure(1)
bar(string(drop_height), [sucessful_catches ./ (50 - infeasibilities), sucessful_catches_s ./ (50 - infeasibilities_s)]  * 100, "BarWidth", 0.8)
title("Catch Rate vs Drop Height")
subtitle("Feasible Catches Only")
xlabel("Drop Height (m)")
ylabel("Catch Rate %")
legend('First Propagation Only', "Velocity Minimization")

figure(2)
bar(string(drop_height), [collisions ./ (50 - infeasibilities), collisions_s ./ (50 - infeasibilities_s)] * 100, "BarWidth", 0.8)
title("Collision Rate vs Drop Height")
subtitle("Feasible Catches Only")
xlabel("Drop Height (m)")
ylabel("Collision Rate %")
legend('First Propagation Only', "Velocity Minimization")


figure(3)
bar(string(drop_height), [agent_effort ./ (50 - infeasibilities), agent_effort_s ./ (50 - infeasibilities_s)], "BarWidth", 0.8)
title("Agent Effort vs Drop Height")
subtitle("Feasible Catches Only")
xlabel("Drop Height (m)")
ylabel("Total Agent Effort")
legend('First Propagation Only', "Velocity Minimization")


figure(4)
bar(string(drop_height), [infeasibilities / 50, infeasibilities_s / 50] * 100, "BarWidth", .8)
title("Infeasiblities vs Drop Height")
xlabel("Drop Height (m)")
ylabel("Infeasible Catches %")
legend('First Propagation Only', "Velocity Minimization")

figure(5)
bar(string(drop_height), [(infeasibilities) ./ ((50 - sucessful_catches)), (infeasibilities_s) ./ ((50 - sucessful_catches_s))] * 100, "BarWidth", .8)
title("Infeasibility Detection Rate")
xlabel("Drop Height (m)")
ylabel("Detwction Rate %")
legend('First Propagation Only', "Velocity Minimization")

sum(infeasibilities_s) / (450 - sum(sucessful_catches_s))
sum(infeasibilities) / (450 - sum(sucessful_catches))