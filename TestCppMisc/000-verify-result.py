import math
#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
print('exprStr = ', '557.0*458.0-946.0/67.0-658.0+59.0-54.0*577.0-372.0*621.0*956.0-382.0-14.0-275.0/317.0-283.0-542.0-931.0+310.0+400.0-904.0-516.0+450.0*3.0/17.0/854.0*326.0-873.0/169.0+921.0*616.0+303.0-465.0-440.0+430.0+725.0/296.0*511.0*556.0/505.0+512.0*783.0+142.0-585.0-452.0+709.0-877.0/409.0/103.0*167.0-979.0-886.0+839.0-994.0+446.0+382.0*833.0*9.0*977.0/225.0*325.0+965.0+44.0*915.0-817.0-336.0+102.0+783.0/922.0+292.0/393.0-404.0/45.0+957.0/764.0*110.0/285.0*940.0/183.0-420.0*8.0/60.0+895.0/295.0/18.0-539.0/77.0+217.0*678.0-896.0-480.0+227.0/629.0+324.0*617.0+289.0*901.0-368.0*789.0+424.0+812.0+190.0/691.0/394.0/181.0-979.0-26.0/78.0+557.0-481.0/149.0/151.0/600.0-230.0-304.0*964.0/436.0+439.0-865.0*515.0+330.0+899.0*932.0*166.0-810.0+963.0/221.0-681.0+972.0*176.0+682.0*616.0-184.0*598.0/248.0+407.0*905.0/131.0/658.0+994.0/942.0-249.0-227.0-560.0/406.0/689.0+725.0+844.0*478.0*337.0*794.0*936.0-902.0-460.0/146.0+458.0+960.0*240.0+767.0-597.0/924.0/936.0-575.0/617.0-47.0+583.0-14.0*614.0/262.0*56.0*895.0+619.0/980.0+358.0+146.0-908.0/123.0*666.0+953.0*769.0+311.0-857.0*389.0*651.0+88.0+722.0*986.0+885.0+964.0-1000.0*439.0+401.0-174.0+97.0-152.0-87.0-781.0+116.0*858.0*772.0*10.0+141.0-105.0+13.0-651.0+609.0+68.0+184.0-959.0+48.0*816.0*659.0*698.0+747.0+554.0/516.0/111.0+111.0+172.0+746.0+441.0-281.0+730.0/228.0-163.0/799.0+244.0*135.0*873.0*18.0*375.0-904.0*589.0-106.0-39.0*885.0+511.0/796.0/549.0/964.0/115.0/505.0+800.0+155.0*597.0*254.0*569.0+506.0-899.0*461.0-657.0/106.0+355.0-247.0/845.0+512.0*969.0/658.0-845.0/639.0/401.0+696.0-311.0/757.0-945.0-640.0+915.0/614.0/430.0*502.0+705.0-172.0+229.0+571.0/698.0-412.0+993.0-211.0/584.0+333.0+877.0/594.0-145.0-142.0-635.0/288.0-99.0-667.0-524.0+443.0+474.0-946.0+7.0/177.0/538.0+357.0*334.0+266.0*538.0-965.0*258.0/948.0*112.0-796.0-641.0/617.0/248.0+180.0-679.0+348.0+959.0/603.0+642.0/483.0-577.0*410.0/511.0-427.0+235.0-47.0/27.0-62.0+94.0-162.0+327.0/924.0/208.0/896.0*57.0-967.0*789.0+891.0/914.0+600.0*448.0+481.0+206.0-527.0+356.0+672.0/868.0+91.0-467.0*166.0-232.0*444.0/153.0/162.0*756.0/242.0+920.0*164.0+606.0/385.0/431.0-668.0+610.0+957.0/874.0/341.0+708.0*793.0*807.0-553.0*932.0-315.0-586.0*571.0/736.0-648.0+129.0*223.0*112.0-91.0+714.0-795.0-674.0-127.0/854.0+342.0+458.0/280.0+470.0*948.0*490.0/446.0-752.0-323.0/847.0-424.0+824.0-161.0-214.0/835.0*499.0*775.0/846.0*592.0*630.0-899.0+614.0/770.0-43.0-518.0+875.0*760.0+152.0+885.0*151.0/716.0+492.0*808.0/510.0-169.0-328.0*27.0*878.0+557.0-478.0-537.0+586.0*682.0*38.0-889.0*774.0-611.0/540.0-698.0/842.0*277.0-371.0-795.0/270.0-171.0-298.0/384.0-138.0+663.0-303.0+168.0*321.0-560.0+576.0*839.0/95.0+817.0/423.0*60.0-957.0+251.0-234.0*753.0/167.0*605.0+979.0-526.0+804.0*406.0-447.0*565.0-853.0-416.0/321.0/752.0-309.0/649.0*638.0+516.0-254.0*791.0*797.0*216.0-924.0/262.0-81.0*642.0+299.0-880.0+878.0*817.0+387.0/554.0-495.0+391.0/957.0*802.0/458.0/23.0-354.0-983.0/90.0+40.0*115.0-964.0+185.0/415.0+909.0+131.0+273.0*555.0+208.0-598.0-903.0/374.0-195.0*926.0*804.0-792.0*700.0/376.0+863.0')

varpy = 557.0*458.0-946.0/67.0-658.0+59.0-54.0*577.0-372.0*621.0*956.0-382.0-14.0-275.0/317.0-283.0-542.0-931.0+310.0+400.0-904.0-516.0+450.0*3.0/17.0/854.0*326.0-873.0/169.0+921.0*616.0+303.0-465.0-440.0+430.0+725.0/296.0*511.0*556.0/505.0+512.0*783.0+142.0-585.0-452.0+709.0-877.0/409.0/103.0*167.0-979.0-886.0+839.0-994.0+446.0+382.0*833.0*9.0*977.0/225.0*325.0+965.0+44.0*915.0-817.0-336.0+102.0+783.0/922.0+292.0/393.0-404.0/45.0+957.0/764.0*110.0/285.0*940.0/183.0-420.0*8.0/60.0+895.0/295.0/18.0-539.0/77.0+217.0*678.0-896.0-480.0+227.0/629.0+324.0*617.0+289.0*901.0-368.0*789.0+424.0+812.0+190.0/691.0/394.0/181.0-979.0-26.0/78.0+557.0-481.0/149.0/151.0/600.0-230.0-304.0*964.0/436.0+439.0-865.0*515.0+330.0+899.0*932.0*166.0-810.0+963.0/221.0-681.0+972.0*176.0+682.0*616.0-184.0*598.0/248.0+407.0*905.0/131.0/658.0+994.0/942.0-249.0-227.0-560.0/406.0/689.0+725.0+844.0*478.0*337.0*794.0*936.0-902.0-460.0/146.0+458.0+960.0*240.0+767.0-597.0/924.0/936.0-575.0/617.0-47.0+583.0-14.0*614.0/262.0*56.0*895.0+619.0/980.0+358.0+146.0-908.0/123.0*666.0+953.0*769.0+311.0-857.0*389.0*651.0+88.0+722.0*986.0+885.0+964.0-1000.0*439.0+401.0-174.0+97.0-152.0-87.0-781.0+116.0*858.0*772.0*10.0+141.0-105.0+13.0-651.0+609.0+68.0+184.0-959.0+48.0*816.0*659.0*698.0+747.0+554.0/516.0/111.0+111.0+172.0+746.0+441.0-281.0+730.0/228.0-163.0/799.0+244.0*135.0*873.0*18.0*375.0-904.0*589.0-106.0-39.0*885.0+511.0/796.0/549.0/964.0/115.0/505.0+800.0+155.0*597.0*254.0*569.0+506.0-899.0*461.0-657.0/106.0+355.0-247.0/845.0+512.0*969.0/658.0-845.0/639.0/401.0+696.0-311.0/757.0-945.0-640.0+915.0/614.0/430.0*502.0+705.0-172.0+229.0+571.0/698.0-412.0+993.0-211.0/584.0+333.0+877.0/594.0-145.0-142.0-635.0/288.0-99.0-667.0-524.0+443.0+474.0-946.0+7.0/177.0/538.0+357.0*334.0+266.0*538.0-965.0*258.0/948.0*112.0-796.0-641.0/617.0/248.0+180.0-679.0+348.0+959.0/603.0+642.0/483.0-577.0*410.0/511.0-427.0+235.0-47.0/27.0-62.0+94.0-162.0+327.0/924.0/208.0/896.0*57.0-967.0*789.0+891.0/914.0+600.0*448.0+481.0+206.0-527.0+356.0+672.0/868.0+91.0-467.0*166.0-232.0*444.0/153.0/162.0*756.0/242.0+920.0*164.0+606.0/385.0/431.0-668.0+610.0+957.0/874.0/341.0+708.0*793.0*807.0-553.0*932.0-315.0-586.0*571.0/736.0-648.0+129.0*223.0*112.0-91.0+714.0-795.0-674.0-127.0/854.0+342.0+458.0/280.0+470.0*948.0*490.0/446.0-752.0-323.0/847.0-424.0+824.0-161.0-214.0/835.0*499.0*775.0/846.0*592.0*630.0-899.0+614.0/770.0-43.0-518.0+875.0*760.0+152.0+885.0*151.0/716.0+492.0*808.0/510.0-169.0-328.0*27.0*878.0+557.0-478.0-537.0+586.0*682.0*38.0-889.0*774.0-611.0/540.0-698.0/842.0*277.0-371.0-795.0/270.0-171.0-298.0/384.0-138.0+663.0-303.0+168.0*321.0-560.0+576.0*839.0/95.0+817.0/423.0*60.0-957.0+251.0-234.0*753.0/167.0*605.0+979.0-526.0+804.0*406.0-447.0*565.0-853.0-416.0/321.0/752.0-309.0/649.0*638.0+516.0-254.0*791.0*797.0*216.0-924.0/262.0-81.0*642.0+299.0-880.0+878.0*817.0+387.0/554.0-495.0+391.0/957.0*802.0/458.0/23.0-354.0-983.0/90.0+40.0*115.0-964.0+185.0/415.0+909.0+131.0+273.0*555.0+208.0-598.0-903.0/374.0-195.0*926.0*804.0-792.0*700.0/376.0+863.0
print('varpy  = ', varpy)

varcpp = 101236453969489
print('varcpp = ', varcpp)

print('varpy == varcpp?', varpy == varcpp)
print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))
print()
#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

'''
'''
#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
print('exprStr = ', '773.0*935.0+681.0*607.0-716.0/(216.0+599.0-84.0-718.0+469.0*804.0*342.0/240.0*928.0/289.0-515.0)/57.0/647.0/964.0+611.0/715.0+680.0+159.0-23.0/652.0/70.0*959.0+42.0-929.0-701.0/652.0*164.0*269.0-184.0+882.0/623.0*863.0+247.0*37.0+896.0+773.0+190.0*871.0-276.0/662.0+974.0+587.0-939.0+352.0/493.0+14.0*997.0/325.0/972.0+10.0+74.0/926.0+946.0+681.0/522.0-268.0-528.0+211.0-923.0-261.0+74.0+108.0*208.0+859.0/814.0/47.0+842.0-39.0/(653.0/523.0/513.0*325.0*156.0-648.0*14.0+859.0+668.0*90.0+225.0-45.0-133.0)+653.0*644.0*167.0+590.0/498.0/852.0/715.0+44.0-735.0*409.0/339.0/514.0-666.0/597.0*29.0*324.0-633.0-119.0+217.0+782.0-633.0-945.0-348.0/768.0+713.0/307.0/22.0+227.0-104.0/28.0+72.0/418.0-462.0/819.0/888.0+289.0/330.0+480.0/813.0+313.0*730.0+422.0-239.0*983.0/401.0-47.0-921.0/23.0/759.0-214.0*221.0/162.0/65.0+69.0*787.0-741.0-392.0+824.0-482.0*580.0+839.0+78.0*788.0-926.0+678.0/47.0/107.0*916.0*853.0-361.0/862.0+86.0+882.0*268.0-483.0-835.0-277.0-199.0-605.0-998.0-448.0*79.0-827.0*750.0-267.0+851.0/615.0/395.0+542.0-139.0/612.0+507.0*197.0+520.0/198.0*225.0*331.0*965.0/688.0-576.0*79.0/259.0*785.0+336.0+996.0-835.0-119.0/276.0*289.0*313.0+928.0/87.0*407.0*696.0+275.0*698.0-561.0/479.0+919.0*948.0*738.0+708.0-133.0*529.0*756.0*821.0+557.0-465.0+90.0/973.0*969.0/996.0*773.0*705.0+960.0/992.0*128.0+551.0-47.0-911.0/1.0*881.0-358.0*12.0-748.0*297.0+361.0*614.0-762.0*817.0/(258.0*80.0+833.0+360.0/651.0-405.0+270.0/597.0*9.0-788.0/442.0-568.0*671.0/916.0/933.0)-304.0*56.0/318.0-233.0+991.0-56.0*500.0+937.0+185.0+853.0*728.0*651.0+202.0-746.0*597.0+(37.0/375.0/782.0-599.0-803.0+561.0+391.0+571.0/269.0+65.0+345.0-867.0-351.0/408.0/667.0-365.0-99.0+8.0+221.0-226.0*517.0-428.0*263.0*152.0/776.0*332.0+36.0/162.0*146.0/920.0+563.0)-521.0-698.0-786.0-715.0+543.0+703.0*888.0*555.0-980.0*(806.0+719.0+451.0/515.0/82.0+950.0+171.0/910.0/695.0+629.0*125.0*682.0/462.0-494.0/847.0/967.0+358.0*235.0-960.0*131.0/490.0-308.0*542.0-107.0+636.0*896.0*219.0+560.0-857.0*766.0+274.0/369.0-245.0+276.0-368.0-216.0+948.0/101.0/896.0-273.0+415.0*172.0*687.0-774.0*751.0*459.0-578.0+438.0/396.0+576.0-975.0+853.0-661.0/959.0/634.0-76.0+98.0*632.0)*991.0*106.0/156.0*852.0/691.0*76.0/806.0-218.0*825.0+65.0*198.0-360.0/913.0/702.0+283.0+976.0-217.0-123.0+199.0+53.0-624.0+525.0-397.0+147.0/581.0/95.0-762.0/623.0*647.0+350.0+369.0/429.0/602.0/778.0*605.0/247.0-828.0*951.0+385.0-85.0-555.0/129.0/(990.0+986.0)/353.0-502.0+258.0/809.0*511.0/317.0*862.0*37.0/845.0/178.0+375.0*926.0-792.0/57.0*214.0-993.0+745.0+694.0+896.0+904.0+266.0*701.0-216.0/846.0/433.0/191.0*463.0-242.0+126.0-154.0*420.0*612.0-920.0-646.0/712.0+693.0-91.0-435.0/73.0+417.0/368.0/460.0/381.0-621.0*333.0*728.0*332.0-697.0*18.0-907.0/651.0/402.0+492.0*673.0*560.0*861.0/420.0+(834.0/778.0/938.0+624.0-888.0-78.0-377.0*435.0-812.0/427.0)/304.0+793.0/167.0-802.0-46.0*773.0/645.0+917.0-378.0-777.0-891.0*590.0/23.0+614.0+254.0+821.0/376.0/740.0-617.0+371.0+419.0-345.0-338.0-312.0-675.0/94.0+183.0-734.0+351.0+241.0-96.0+18.0/201.0*610.0-660.0+14.0')

varpy = 773.0*935.0+681.0*607.0-716.0/(216.0+599.0-84.0-718.0+469.0*804.0*342.0/240.0*928.0/289.0-515.0)/57.0/647.0/964.0+611.0/715.0+680.0+159.0-23.0/652.0/70.0*959.0+42.0-929.0-701.0/652.0*164.0*269.0-184.0+882.0/623.0*863.0+247.0*37.0+896.0+773.0+190.0*871.0-276.0/662.0+974.0+587.0-939.0+352.0/493.0+14.0*997.0/325.0/972.0+10.0+74.0/926.0+946.0+681.0/522.0-268.0-528.0+211.0-923.0-261.0+74.0+108.0*208.0+859.0/814.0/47.0+842.0-39.0/(653.0/523.0/513.0*325.0*156.0-648.0*14.0+859.0+668.0*90.0+225.0-45.0-133.0)+653.0*644.0*167.0+590.0/498.0/852.0/715.0+44.0-735.0*409.0/339.0/514.0-666.0/597.0*29.0*324.0-633.0-119.0+217.0+782.0-633.0-945.0-348.0/768.0+713.0/307.0/22.0+227.0-104.0/28.0+72.0/418.0-462.0/819.0/888.0+289.0/330.0+480.0/813.0+313.0*730.0+422.0-239.0*983.0/401.0-47.0-921.0/23.0/759.0-214.0*221.0/162.0/65.0+69.0*787.0-741.0-392.0+824.0-482.0*580.0+839.0+78.0*788.0-926.0+678.0/47.0/107.0*916.0*853.0-361.0/862.0+86.0+882.0*268.0-483.0-835.0-277.0-199.0-605.0-998.0-448.0*79.0-827.0*750.0-267.0+851.0/615.0/395.0+542.0-139.0/612.0+507.0*197.0+520.0/198.0*225.0*331.0*965.0/688.0-576.0*79.0/259.0*785.0+336.0+996.0-835.0-119.0/276.0*289.0*313.0+928.0/87.0*407.0*696.0+275.0*698.0-561.0/479.0+919.0*948.0*738.0+708.0-133.0*529.0*756.0*821.0+557.0-465.0+90.0/973.0*969.0/996.0*773.0*705.0+960.0/992.0*128.0+551.0-47.0-911.0/1.0*881.0-358.0*12.0-748.0*297.0+361.0*614.0-762.0*817.0/(258.0*80.0+833.0+360.0/651.0-405.0+270.0/597.0*9.0-788.0/442.0-568.0*671.0/916.0/933.0)-304.0*56.0/318.0-233.0+991.0-56.0*500.0+937.0+185.0+853.0*728.0*651.0+202.0-746.0*597.0+(37.0/375.0/782.0-599.0-803.0+561.0+391.0+571.0/269.0+65.0+345.0-867.0-351.0/408.0/667.0-365.0-99.0+8.0+221.0-226.0*517.0-428.0*263.0*152.0/776.0*332.0+36.0/162.0*146.0/920.0+563.0)-521.0-698.0-786.0-715.0+543.0+703.0*888.0*555.0-980.0*(806.0+719.0+451.0/515.0/82.0+950.0+171.0/910.0/695.0+629.0*125.0*682.0/462.0-494.0/847.0/967.0+358.0*235.0-960.0*131.0/490.0-308.0*542.0-107.0+636.0*896.0*219.0+560.0-857.0*766.0+274.0/369.0-245.0+276.0-368.0-216.0+948.0/101.0/896.0-273.0+415.0*172.0*687.0-774.0*751.0*459.0-578.0+438.0/396.0+576.0-975.0+853.0-661.0/959.0/634.0-76.0+98.0*632.0)*991.0*106.0/156.0*852.0/691.0*76.0/806.0-218.0*825.0+65.0*198.0-360.0/913.0/702.0+283.0+976.0-217.0-123.0+199.0+53.0-624.0+525.0-397.0+147.0/581.0/95.0-762.0/623.0*647.0+350.0+369.0/429.0/602.0/778.0*605.0/247.0-828.0*951.0+385.0-85.0-555.0/129.0/(990.0+986.0)/353.0-502.0+258.0/809.0*511.0/317.0*862.0*37.0/845.0/178.0+375.0*926.0-792.0/57.0*214.0-993.0+745.0+694.0+896.0+904.0+266.0*701.0-216.0/846.0/433.0/191.0*463.0-242.0+126.0-154.0*420.0*612.0-920.0-646.0/712.0+693.0-91.0-435.0/73.0+417.0/368.0/460.0/381.0-621.0*333.0*728.0*332.0-697.0*18.0-907.0/651.0/402.0+492.0*673.0*560.0*861.0/420.0+(834.0/778.0/938.0+624.0-888.0-78.0-377.0*435.0-812.0/427.0)/304.0+793.0/167.0-802.0-46.0*773.0/645.0+917.0-378.0-777.0-891.0*590.0/23.0+614.0+254.0+821.0/376.0/740.0-617.0+371.0+419.0-345.0-338.0-312.0-675.0/94.0+183.0-734.0+351.0+241.0-96.0+18.0/201.0*610.0-660.0+14.0
print('varpy  = ', varpy)

varcpp = 7083813875666.69
print('varcpp = ', varcpp)

print('varpy == varcpp?', varpy == varcpp)
print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))
print()
#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

'''
'''
#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
print('exprStr = ', '113.0/552.0/632.0/544.0-355.0-420.0+(84.0+996.0*282.0*789.0*627.0/825.0+797.0-153.0*42.0-619.0+537.0*392.0-700.0+388.0/291.0*747.0+502.0/908.0*149.0-869.0+976.0-985.0-143.0/516.0-10.0-203.0*768.0/222.0-808.0-163.0)+43.0+450.0+340.0-(224.0/788.0*207.0-384.0+513.0+468.0+226.0*841.0*724.0-335.0-39.0/260.0*292.0)-806.0-738.0/213.0/696.0+283.0-251.0/493.0/939.0*770.0-556.0/496.0+659.0*975.0-341.0*775.0-1.0/252.0-461.0+1000.0-934.0+310.0/303.0+77.0/272.0-88.0*366.0/625.0-121.0*500.0/687.0+73.0+154.0-432.0+895.0*454.0-259.0+236.0*(249.0+968.0/219.0-762.0*544.0/588.0/415.0*390.0*807.0/469.0/696.0+824.0/14.0-186.0+888.0-751.0+550.0*596.0+602.0-45.0-776.0+895.0*838.0-224.0-617.0+657.0*973.0*977.0-845.0+59.0-562.0+463.0+567.0/242.0*335.0*770.0-621.0/601.0+192.0+770.0+87.0*895.0*372.0-906.0+136.0/467.0/309.0+751.0-411.0-151.0/54.0*891.0+785.0-511.0-809.0/410.0-954.0+747.0-179.0*205.0*89.0/43.0/478.0/814.0*635.0+525.0+974.0*968.0*236.0+483.0/761.0-109.0+21.0*428.0*86.0+50.0+682.0*271.0)*675.0-959.0*263.0*956.0-91.0/748.0*650.0+521.0+125.0*687.0*196.0*559.0*128.0/228.0*732.0-278.0-727.0-361.0/491.0+659.0/290.0/497.0*664.0+626.0*(242.0*77.0/897.0-895.0*854.0*166.0-747.0-909.0*776.0+885.0*463.0/330.0+966.0)*423.0-324.0*655.0+626.0+347.0+489.0+18.0-323.0/866.0/962.0*(750.0-53.0*25.0*621.0*751.0/848.0-498.0*753.0+887.0)+773.0*609.0-757.0*263.0-227.0*(770.0*894.0/73.0-705.0-568.0-816.0*970.0-76.0/197.0/505.0+591.0*629.0+18.0*267.0/307.0-109.0/658.0/396.0*351.0-425.0+167.0-764.0-980.0/513.0*703.0*446.0/543.0-451.0*764.0+750.0-101.0/294.0+655.0*296.0/34.0*530.0-653.0+205.0+292.0+296.0*847.0+38.0*324.0+933.0/735.0-952.0-621.0*889.0-21.0-280.0-847.0/759.0/316.0-402.0/159.0/778.0-595.0+611.0*349.0-853.0/969.0*569.0-190.0*372.0+881.0-919.0/792.0/212.0+46.0*479.0+568.0*88.0*434.0*987.0+143.0-562.0*808.0/615.0*940.0)-54.0*202.0-(25.0/597.0-35.0*413.0-86.0/814.0/97.0*803.0*357.0*292.0*488.0/821.0*584.0+151.0-910.0-865.0*867.0-39.0*427.0+679.0-787.0-369.0+554.0/678.0*860.0)+181.0/722.0/700.0+917.0/241.0*242.0*857.0*594.0*32.0+417.0*689.0/430.0+275.0/209.0*793.0/351.0/458.0*711.0/337.0+315.0/792.0+732.0*922.0/532.0+466.0*944.0/62.0+701.0*459.0*122.0-893.0/141.0-640.0-631.0+886.0-301.0/706.0*495.0-499.0-975.0+375.0-(472.0-865.0+301.0/519.0+395.0/975.0*583.0/938.0*686.0)-531.0*138.0/98.0-957.0*566.0-987.0*994.0*35.0/112.0/496.0/137.0-835.0-396.0/(321.0+709.0-266.0-808.0/207.0/802.0+512.0*25.0/848.0/988.0+224.0*526.0/335.0/803.0-327.0)*(117.0/17.0+176.0*244.0+523.0/51.0*598.0-358.0*811.0+332.0-65.0*641.0-483.0-607.0*604.0*122.0+376.0+772.0-966.0*786.0/110.0+786.0-522.0-578.0-182.0*312.0*36.0/334.0*461.0/204.0*88.0+611.0+70.0*74.0/697.0/675.0-472.0-258.0-517.0-723.0+433.0*770.0/798.0*237.0*696.0-474.0)+696.0-941.0+153.0/496.0*381.0-735.0*175.0+36.0/534.0/(883.0-232.0-618.0/111.0/928.0)*215.0/288.0-833.0*151.0+306.0*567.0-478.0*809.0*480.0+230.0/542.0+233.0/683.0/324.0*785.0*612.0+754.0+451.0/425.0*218.0*276.0/521.0*764.0+524.0+282.0+168.0-533.0-162.0-466.0-933.0*373.0-105.0/210.0/959.0*584.0/536.0+460.0*107.0-808.0')

varpy = 113.0/552.0/632.0/544.0-355.0-420.0+(84.0+996.0*282.0*789.0*627.0/825.0+797.0-153.0*42.0-619.0+537.0*392.0-700.0+388.0/291.0*747.0+502.0/908.0*149.0-869.0+976.0-985.0-143.0/516.0-10.0-203.0*768.0/222.0-808.0-163.0)+43.0+450.0+340.0-(224.0/788.0*207.0-384.0+513.0+468.0+226.0*841.0*724.0-335.0-39.0/260.0*292.0)-806.0-738.0/213.0/696.0+283.0-251.0/493.0/939.0*770.0-556.0/496.0+659.0*975.0-341.0*775.0-1.0/252.0-461.0+1000.0-934.0+310.0/303.0+77.0/272.0-88.0*366.0/625.0-121.0*500.0/687.0+73.0+154.0-432.0+895.0*454.0-259.0+236.0*(249.0+968.0/219.0-762.0*544.0/588.0/415.0*390.0*807.0/469.0/696.0+824.0/14.0-186.0+888.0-751.0+550.0*596.0+602.0-45.0-776.0+895.0*838.0-224.0-617.0+657.0*973.0*977.0-845.0+59.0-562.0+463.0+567.0/242.0*335.0*770.0-621.0/601.0+192.0+770.0+87.0*895.0*372.0-906.0+136.0/467.0/309.0+751.0-411.0-151.0/54.0*891.0+785.0-511.0-809.0/410.0-954.0+747.0-179.0*205.0*89.0/43.0/478.0/814.0*635.0+525.0+974.0*968.0*236.0+483.0/761.0-109.0+21.0*428.0*86.0+50.0+682.0*271.0)*675.0-959.0*263.0*956.0-91.0/748.0*650.0+521.0+125.0*687.0*196.0*559.0*128.0/228.0*732.0-278.0-727.0-361.0/491.0+659.0/290.0/497.0*664.0+626.0*(242.0*77.0/897.0-895.0*854.0*166.0-747.0-909.0*776.0+885.0*463.0/330.0+966.0)*423.0-324.0*655.0+626.0+347.0+489.0+18.0-323.0/866.0/962.0*(750.0-53.0*25.0*621.0*751.0/848.0-498.0*753.0+887.0)+773.0*609.0-757.0*263.0-227.0*(770.0*894.0/73.0-705.0-568.0-816.0*970.0-76.0/197.0/505.0+591.0*629.0+18.0*267.0/307.0-109.0/658.0/396.0*351.0-425.0+167.0-764.0-980.0/513.0*703.0*446.0/543.0-451.0*764.0+750.0-101.0/294.0+655.0*296.0/34.0*530.0-653.0+205.0+292.0+296.0*847.0+38.0*324.0+933.0/735.0-952.0-621.0*889.0-21.0-280.0-847.0/759.0/316.0-402.0/159.0/778.0-595.0+611.0*349.0-853.0/969.0*569.0-190.0*372.0+881.0-919.0/792.0/212.0+46.0*479.0+568.0*88.0*434.0*987.0+143.0-562.0*808.0/615.0*940.0)-54.0*202.0-(25.0/597.0-35.0*413.0-86.0/814.0/97.0*803.0*357.0*292.0*488.0/821.0*584.0+151.0-910.0-865.0*867.0-39.0*427.0+679.0-787.0-369.0+554.0/678.0*860.0)+181.0/722.0/700.0+917.0/241.0*242.0*857.0*594.0*32.0+417.0*689.0/430.0+275.0/209.0*793.0/351.0/458.0*711.0/337.0+315.0/792.0+732.0*922.0/532.0+466.0*944.0/62.0+701.0*459.0*122.0-893.0/141.0-640.0-631.0+886.0-301.0/706.0*495.0-499.0-975.0+375.0-(472.0-865.0+301.0/519.0+395.0/975.0*583.0/938.0*686.0)-531.0*138.0/98.0-957.0*566.0-987.0*994.0*35.0/112.0/496.0/137.0-835.0-396.0/(321.0+709.0-266.0-808.0/207.0/802.0+512.0*25.0/848.0/988.0+224.0*526.0/335.0/803.0-327.0)*(117.0/17.0+176.0*244.0+523.0/51.0*598.0-358.0*811.0+332.0-65.0*641.0-483.0-607.0*604.0*122.0+376.0+772.0-966.0*786.0/110.0+786.0-522.0-578.0-182.0*312.0*36.0/334.0*461.0/204.0*88.0+611.0+70.0*74.0/697.0/675.0-472.0-258.0-517.0-723.0+433.0*770.0/798.0*237.0*696.0-474.0)+696.0-941.0+153.0/496.0*381.0-735.0*175.0+36.0/534.0/(883.0-232.0-618.0/111.0/928.0)*215.0/288.0-833.0*151.0+306.0*567.0-478.0*809.0*480.0+230.0/542.0+233.0/683.0/324.0*785.0*612.0+754.0+451.0/425.0*218.0*276.0/521.0*764.0+524.0+282.0+168.0-533.0-162.0-466.0-933.0*373.0-105.0/210.0/959.0*584.0/536.0+460.0*107.0-808.0
print('varpy  = ', varpy)

varcpp = 105208833948417
print('varcpp = ', varcpp)

print('varpy == varcpp?', varpy == varcpp)
print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))
print()
#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

'''
'''
#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
print('exprStr = ', '805.0*744.0*613.0-278.0/566.0/241.0-901.0/740.0/104.0/799.0*826.0-314.0/903.0-(323.0+804.0*840.0*865.0-48.0*320.0-923.0*819.0+153.0/438.0*651.0/657.0+859.0/558.0/546.0+757.0/98.0-772.0*695.0*71.0*922.0/404.0*662.0-551.0-771.0*282.0+287.0+533.0/359.0-957.0*765.0/145.0-462.0+819.0-46.0*634.0-363.0+899.0/745.0-683.0+882.0/67.0+413.0+299.0/465.0*529.0-979.0*502.0/535.0+81.0+318.0-416.0+17.0-943.0-61.0/837.0+226.0+188.0-509.0+629.0+633.0*17.0-651.0+193.0-74.0)/113.0-136.0/68.0*17.0*354.0/396.0/830.0+289.0/355.0*(715.0-138.0-446.0-496.0/366.0/570.0-971.0*890.0-465.0*838.0/185.0/858.0*103.0-955.0-778.0-736.0*111.0-452.0/386.0-245.0)+900.0*745.0+49.0+495.0+17.0/67.0/294.0+(275.0+128.0+584.0*919.0+397.0-626.0*998.0)-797.0*834.0-984.0+661.0/776.0+62.0*(829.0*337.0-965.0/73.0*925.0)-(498.0/153.0*554.0*890.0+193.0*360.0/368.0*319.0+170.0/42.0+405.0*206.0*372.0+644.0/938.0/615.0-217.0+735.0-403.0*404.0)*47.0*131.0-524.0/834.0-64.0*841.0/(645.0/341.0/84.0+651.0-420.0+883.0+535.0*591.0)/912.0/724.0*(236.0*147.0/455.0+526.0*13.0*243.0-866.0/738.0*154.0*35.0+426.0/81.0/211.0*338.0-277.0*472.0/618.0+300.0+397.0*123.0*784.0/307.0*932.0*255.0/224.0-811.0/601.0*515.0)*862.0*917.0+363.0-759.0/766.0*641.0/741.0+92.0/970.0+(914.0+229.0)/34.0+860.0/340.0/147.0+153.0*(130.0+906.0*351.0/971.0)*551.0*884.0+325.0*170.0/473.0+979.0-866.0-698.0-351.0-404.0/384.0+306.0*374.0-827.0-132.0/290.0*529.0-990.0+564.0-481.0*557.0-850.0*44.0*752.0-941.0-501.0/375.0+400.0*844.0+749.0/251.0/686.0-650.0/631.0/600.0*(530.0-942.0+732.0/377.0/237.0*333.0/851.0*732.0)*173.0*443.0/116.0+126.0*203.0*161.0/160.0+727.0*672.0-5.0/372.0-856.0-257.0/672.0/874.0-227.0*916.0-294.0/463.0+535.0+238.0+763.0-830.0+837.0+530.0/377.0*794.0*20.0/90.0-433.0/721.0/677.0-364.0*17.0*101.0+468.0+819.0+271.0-335.0/216.0+685.0+390.0+380.0-60.0*77.0*(426.0+982.0/268.0-130.0+409.0)*757.0+964.0-462.0/566.0+778.0*666.0/4.0/317.0+34.0-359.0+833.0/725.0*(414.0+893.0/365.0+429.0*723.0/305.0+352.0/176.0-325.0+881.0)+39.0+363.0/638.0/75.0/29.0+105.0+72.0-792.0/862.0/55.0+588.0*252.0-202.0/509.0/745.0*539.0/137.0/502.0-954.0-812.0-309.0+422.0-366.0-610.0-894.0+667.0/561.0*(112.0*333.0*79.0-297.0/464.0+536.0-233.0/851.0/860.0*612.0+485.0-505.0)*686.0*675.0*64.0-280.0+209.0*26.0+61.0/289.0+172.0+314.0-728.0/67.0+440.0-330.0+172.0-898.0*217.0+869.0+(398.0-866.0/156.0+126.0+242.0*498.0*927.0/275.0/932.0+793.0+173.0+589.0*437.0+159.0-998.0+502.0*563.0*968.0/259.0/234.0+462.0/77.0/85.0-893.0*183.0/499.0*991.0*442.0)+813.0-235.0+713.0-170.0*145.0/411.0/189.0-984.0-525.0*346.0-819.0-714.0+31.0-315.0*455.0-827.0/779.0/674.0/(220.0-838.0/767.0/742.0-109.0-640.0-858.0/644.0*122.0/571.0-53.0)+8.0*793.0/306.0-595.0+736.0+443.0/957.0*3.0*(793.0+601.0)/175.0*683.0/901.0+112.0-84.0+174.0/79.0+893.0*195.0-422.0+600.0-514.0+357.0/347.0-911.0*540.0-767.0*283.0*231.0+711.0+657.0/803.0*496.0*(274.0*623.0*519.0/441.0-565.0*309.0-42.0-617.0+793.0/375.0*92.0-472.0+743.0-266.0+241.0/790.0*3.0/611.0*611.0*132.0)-42.0-695.0+715.0*250.0/337.0*432.0*180.0+679.0*33.0-726.0-317.0/480.0*907.0')

varpy = 805.0*744.0*613.0-278.0/566.0/241.0-901.0/740.0/104.0/799.0*826.0-314.0/903.0-(323.0+804.0*840.0*865.0-48.0*320.0-923.0*819.0+153.0/438.0*651.0/657.0+859.0/558.0/546.0+757.0/98.0-772.0*695.0*71.0*922.0/404.0*662.0-551.0-771.0*282.0+287.0+533.0/359.0-957.0*765.0/145.0-462.0+819.0-46.0*634.0-363.0+899.0/745.0-683.0+882.0/67.0+413.0+299.0/465.0*529.0-979.0*502.0/535.0+81.0+318.0-416.0+17.0-943.0-61.0/837.0+226.0+188.0-509.0+629.0+633.0*17.0-651.0+193.0-74.0)/113.0-136.0/68.0*17.0*354.0/396.0/830.0+289.0/355.0*(715.0-138.0-446.0-496.0/366.0/570.0-971.0*890.0-465.0*838.0/185.0/858.0*103.0-955.0-778.0-736.0*111.0-452.0/386.0-245.0)+900.0*745.0+49.0+495.0+17.0/67.0/294.0+(275.0+128.0+584.0*919.0+397.0-626.0*998.0)-797.0*834.0-984.0+661.0/776.0+62.0*(829.0*337.0-965.0/73.0*925.0)-(498.0/153.0*554.0*890.0+193.0*360.0/368.0*319.0+170.0/42.0+405.0*206.0*372.0+644.0/938.0/615.0-217.0+735.0-403.0*404.0)*47.0*131.0-524.0/834.0-64.0*841.0/(645.0/341.0/84.0+651.0-420.0+883.0+535.0*591.0)/912.0/724.0*(236.0*147.0/455.0+526.0*13.0*243.0-866.0/738.0*154.0*35.0+426.0/81.0/211.0*338.0-277.0*472.0/618.0+300.0+397.0*123.0*784.0/307.0*932.0*255.0/224.0-811.0/601.0*515.0)*862.0*917.0+363.0-759.0/766.0*641.0/741.0+92.0/970.0+(914.0+229.0)/34.0+860.0/340.0/147.0+153.0*(130.0+906.0*351.0/971.0)*551.0*884.0+325.0*170.0/473.0+979.0-866.0-698.0-351.0-404.0/384.0+306.0*374.0-827.0-132.0/290.0*529.0-990.0+564.0-481.0*557.0-850.0*44.0*752.0-941.0-501.0/375.0+400.0*844.0+749.0/251.0/686.0-650.0/631.0/600.0*(530.0-942.0+732.0/377.0/237.0*333.0/851.0*732.0)*173.0*443.0/116.0+126.0*203.0*161.0/160.0+727.0*672.0-5.0/372.0-856.0-257.0/672.0/874.0-227.0*916.0-294.0/463.0+535.0+238.0+763.0-830.0+837.0+530.0/377.0*794.0*20.0/90.0-433.0/721.0/677.0-364.0*17.0*101.0+468.0+819.0+271.0-335.0/216.0+685.0+390.0+380.0-60.0*77.0*(426.0+982.0/268.0-130.0+409.0)*757.0+964.0-462.0/566.0+778.0*666.0/4.0/317.0+34.0-359.0+833.0/725.0*(414.0+893.0/365.0+429.0*723.0/305.0+352.0/176.0-325.0+881.0)+39.0+363.0/638.0/75.0/29.0+105.0+72.0-792.0/862.0/55.0+588.0*252.0-202.0/509.0/745.0*539.0/137.0/502.0-954.0-812.0-309.0+422.0-366.0-610.0-894.0+667.0/561.0*(112.0*333.0*79.0-297.0/464.0+536.0-233.0/851.0/860.0*612.0+485.0-505.0)*686.0*675.0*64.0-280.0+209.0*26.0+61.0/289.0+172.0+314.0-728.0/67.0+440.0-330.0+172.0-898.0*217.0+869.0+(398.0-866.0/156.0+126.0+242.0*498.0*927.0/275.0/932.0+793.0+173.0+589.0*437.0+159.0-998.0+502.0*563.0*968.0/259.0/234.0+462.0/77.0/85.0-893.0*183.0/499.0*991.0*442.0)+813.0-235.0+713.0-170.0*145.0/411.0/189.0-984.0-525.0*346.0-819.0-714.0+31.0-315.0*455.0-827.0/779.0/674.0/(220.0-838.0/767.0/742.0-109.0-640.0-858.0/644.0*122.0/571.0-53.0)+8.0*793.0/306.0-595.0+736.0+443.0/957.0*3.0*(793.0+601.0)/175.0*683.0/901.0+112.0-84.0+174.0/79.0+893.0*195.0-422.0+600.0-514.0+357.0/347.0-911.0*540.0-767.0*283.0*231.0+711.0+657.0/803.0*496.0*(274.0*623.0*519.0/441.0-565.0*309.0-42.0-617.0+793.0/375.0*92.0-472.0+743.0-266.0+241.0/790.0*3.0/611.0*611.0*132.0)-42.0-695.0+715.0*250.0/337.0*432.0*180.0+679.0*33.0-726.0-317.0/480.0*907.0
print('varpy  = ', varpy)

varcpp = 103665134151148
print('varcpp = ', varcpp)

print('varpy == varcpp?', varpy == varcpp)
print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))
print()
#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

'''
'''
#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
print('exprStr = ', '797.0+123.0+(615.0-161.0*223.0+217.0-912.0+49.0+467.0*817.0*267.0/669.0+847.0)*(558.0/23.0/749.0/17.0*456.0*630.0-772.0/867.0+164.0*302.0-831.0)+4.0*102.0+697.0/26.0+(511.0*639.0*953.0)/495.0-915.0+152.0-192.0*(674.0-17.0+211.0-629.0*458.0/663.0*212.0/884.0/492.0*25.0-627.0/412.0-538.0-357.0-755.0-701.0*303.0)-479.0+572.0+240.0-753.0/(466.0+559.0+495.0*48.0/648.0)+258.0/94.0-633.0*888.0/727.0-(30.0/84.0)-712.0*766.0+383.0-736.0-531.0-682.0*48.0/(567.0-646.0/630.0+308.0*520.0-674.0-737.0+804.0)*896.0/620.0+259.0/247.0*163.0*10.0/123.0/712.0-52.0-472.0/642.0*269.0+930.0+253.0-849.0+395.0*822.0-123.0+282.0-423.0-513.0*367.0-(189.0-993.0-948.0/723.0)/542.0/851.0-809.0+850.0*497.0+101.0/418.0-504.0-68.0+514.0*582.0/289.0-(902.0/337.0/628.0/417.0*172.0+513.0+809.0+404.0/908.0)*169.0/640.0+741.0*273.0/598.0+436.0*171.0+596.0*(930.0*560.0+518.0/261.0)/726.0*547.0-331.0/(275.0/472.0-469.0/351.0-949.0)/175.0/825.0*277.0+164.0/20.0*530.0*(975.0+861.0/61.0)*(289.0-159.0/336.0+577.0*278.0*134.0-513.0/743.0*99.0*492.0+848.0/729.0*510.0+865.0-764.0/97.0*400.0+965.0-217.0/254.0/699.0)*38.0/(425.0-619.0)*75.0*557.0/197.0/597.0/434.0*56.0/750.0/854.0+911.0*70.0+303.0+686.0-528.0-101.0-798.0/478.0+162.0+744.0*634.0+(300.0+405.0/646.0/579.0/739.0+231.0/388.0-972.0*96.0-342.0-744.0-857.0-701.0*383.0*703.0-802.0)-(442.0-392.0-436.0/950.0/121.0/843.0/609.0/585.0/634.0-383.0/827.0-802.0)+262.0+380.0*694.0+642.0+703.0/555.0-490.0-640.0*430.0+873.0*810.0*34.0+817.0/193.0*183.0*104.0*553.0+406.0*982.0-(767.0*228.0-792.0/605.0*408.0/105.0-659.0)/96.0+272.0+442.0/328.0+629.0+288.0-752.0/585.0-463.0*452.0*(984.0/647.0+869.0*113.0)-59.0/461.0/50.0*742.0+732.0*418.0-216.0/657.0/744.0/79.0+21.0+742.0*259.0+705.0+532.0*184.0/986.0+756.0/27.0+522.0+766.0-915.0+186.0*434.0/407.0+294.0*331.0-279.0+402.0*775.0/164.0*526.0-513.0+626.0+779.0/911.0-34.0*(569.0*429.0/891.0/315.0/685.0/315.0)-794.0-625.0*248.0-372.0/(887.0-438.0+66.0+969.0-902.0-579.0-733.0+260.0*396.0*74.0)+636.0-(749.0+888.0+556.0-219.0-993.0*357.0/437.0)+862.0*(989.0+253.0+476.0-531.0/985.0/480.0+119.0+262.0+828.0-484.0)-433.0/599.0-563.0+(808.0/480.0/755.0+495.0)/482.0/715.0-700.0-564.0/866.0/968.0-806.0/899.0*110.0-632.0+396.0-118.0+124.0-410.0+(304.0+64.0+631.0/473.0*901.0/287.0+110.0+281.0*298.0*961.0*894.0*407.0/6.0)*186.0-505.0-813.0+258.0+757.0/309.0*774.0/602.0/818.0*(968.0+118.0*714.0*569.0*551.0/401.0*31.0)+295.0/902.0*605.0+970.0/70.0*275.0*98.0/(687.0-861.0/79.0+482.0-692.0)+538.0*269.0/194.0+490.0*616.0*(925.0*959.0-701.0*106.0*742.0/329.0*820.0-258.0)+(251.0/806.0*239.0+493.0+11.0/101.0*992.0-470.0*311.0+534.0-847.0+233.0)+555.0*888.0/347.0-115.0+74.0-179.0+459.0+489.0-872.0*868.0-237.0+767.0/109.0+473.0-656.0+508.0/339.0/161.0*139.0+(933.0+575.0+995.0-40.0/123.0/695.0)-504.0+553.0+13.0+884.0/875.0+219.0+874.0+73.0-527.0-681.0*770.0-687.0+989.0*704.0+528.0-408.0-712.0*648.0*74.0*266.0/378.0+432.0*714.0+110.0*783.0-128.0+747.0-238.0+(932.0-616.0*113.0+316.0-253.0*990.0-802.0*595.0)-48.0+834.0+(679.0/41.0/320.0+227.0/988.0*912.0*874.0*857.0-48.0*517.0/656.0-42.0/952.0)+343.0*246.0')

varpy = 797.0+123.0+(615.0-161.0*223.0+217.0-912.0+49.0+467.0*817.0*267.0/669.0+847.0)*(558.0/23.0/749.0/17.0*456.0*630.0-772.0/867.0+164.0*302.0-831.0)+4.0*102.0+697.0/26.0+(511.0*639.0*953.0)/495.0-915.0+152.0-192.0*(674.0-17.0+211.0-629.0*458.0/663.0*212.0/884.0/492.0*25.0-627.0/412.0-538.0-357.0-755.0-701.0*303.0)-479.0+572.0+240.0-753.0/(466.0+559.0+495.0*48.0/648.0)+258.0/94.0-633.0*888.0/727.0-(30.0/84.0)-712.0*766.0+383.0-736.0-531.0-682.0*48.0/(567.0-646.0/630.0+308.0*520.0-674.0-737.0+804.0)*896.0/620.0+259.0/247.0*163.0*10.0/123.0/712.0-52.0-472.0/642.0*269.0+930.0+253.0-849.0+395.0*822.0-123.0+282.0-423.0-513.0*367.0-(189.0-993.0-948.0/723.0)/542.0/851.0-809.0+850.0*497.0+101.0/418.0-504.0-68.0+514.0*582.0/289.0-(902.0/337.0/628.0/417.0*172.0+513.0+809.0+404.0/908.0)*169.0/640.0+741.0*273.0/598.0+436.0*171.0+596.0*(930.0*560.0+518.0/261.0)/726.0*547.0-331.0/(275.0/472.0-469.0/351.0-949.0)/175.0/825.0*277.0+164.0/20.0*530.0*(975.0+861.0/61.0)*(289.0-159.0/336.0+577.0*278.0*134.0-513.0/743.0*99.0*492.0+848.0/729.0*510.0+865.0-764.0/97.0*400.0+965.0-217.0/254.0/699.0)*38.0/(425.0-619.0)*75.0*557.0/197.0/597.0/434.0*56.0/750.0/854.0+911.0*70.0+303.0+686.0-528.0-101.0-798.0/478.0+162.0+744.0*634.0+(300.0+405.0/646.0/579.0/739.0+231.0/388.0-972.0*96.0-342.0-744.0-857.0-701.0*383.0*703.0-802.0)-(442.0-392.0-436.0/950.0/121.0/843.0/609.0/585.0/634.0-383.0/827.0-802.0)+262.0+380.0*694.0+642.0+703.0/555.0-490.0-640.0*430.0+873.0*810.0*34.0+817.0/193.0*183.0*104.0*553.0+406.0*982.0-(767.0*228.0-792.0/605.0*408.0/105.0-659.0)/96.0+272.0+442.0/328.0+629.0+288.0-752.0/585.0-463.0*452.0*(984.0/647.0+869.0*113.0)-59.0/461.0/50.0*742.0+732.0*418.0-216.0/657.0/744.0/79.0+21.0+742.0*259.0+705.0+532.0*184.0/986.0+756.0/27.0+522.0+766.0-915.0+186.0*434.0/407.0+294.0*331.0-279.0+402.0*775.0/164.0*526.0-513.0+626.0+779.0/911.0-34.0*(569.0*429.0/891.0/315.0/685.0/315.0)-794.0-625.0*248.0-372.0/(887.0-438.0+66.0+969.0-902.0-579.0-733.0+260.0*396.0*74.0)+636.0-(749.0+888.0+556.0-219.0-993.0*357.0/437.0)+862.0*(989.0+253.0+476.0-531.0/985.0/480.0+119.0+262.0+828.0-484.0)-433.0/599.0-563.0+(808.0/480.0/755.0+495.0)/482.0/715.0-700.0-564.0/866.0/968.0-806.0/899.0*110.0-632.0+396.0-118.0+124.0-410.0+(304.0+64.0+631.0/473.0*901.0/287.0+110.0+281.0*298.0*961.0*894.0*407.0/6.0)*186.0-505.0-813.0+258.0+757.0/309.0*774.0/602.0/818.0*(968.0+118.0*714.0*569.0*551.0/401.0*31.0)+295.0/902.0*605.0+970.0/70.0*275.0*98.0/(687.0-861.0/79.0+482.0-692.0)+538.0*269.0/194.0+490.0*616.0*(925.0*959.0-701.0*106.0*742.0/329.0*820.0-258.0)+(251.0/806.0*239.0+493.0+11.0/101.0*992.0-470.0*311.0+534.0-847.0+233.0)+555.0*888.0/347.0-115.0+74.0-179.0+459.0+489.0-872.0*868.0-237.0+767.0/109.0+473.0-656.0+508.0/339.0/161.0*139.0+(933.0+575.0+995.0-40.0/123.0/695.0)-504.0+553.0+13.0+884.0/875.0+219.0+874.0+73.0-527.0-681.0*770.0-687.0+989.0*704.0+528.0-408.0-712.0*648.0*74.0*266.0/378.0+432.0*714.0+110.0*783.0-128.0+747.0-238.0+(932.0-616.0*113.0+316.0-253.0*990.0-802.0*595.0)-48.0+834.0+(679.0/41.0/320.0+227.0/988.0*912.0*874.0*857.0-48.0*517.0/656.0-42.0/952.0)+343.0*246.0
print('varpy  = ', varpy)

varcpp = 866469012858510
print('varcpp = ', varcpp)

print('varpy == varcpp?', varpy == varcpp)
print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))
print()
#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

'''
'''
#BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB
print('exprStr = ', '(223.0*114.0+967.0+665.0+273.0)/697.0*194.0*673.0*539.0-(613.0-514.0-971.0-76.0+946.0/156.0)*407.0*(300.0+701.0/887.0)+(975.0+691.0*422.0+61.0*661.0+930.0-650.0*269.0+886.0*939.0-685.0/732.0-696.0-845.0)*135.0-(266.0/93.0-692.0/200.0-194.0/124.0+422.0*998.0*120.0)/(605.0-170.0*344.0/16.0*330.0)/525.0*(660.0-601.0*232.0)-75.0-395.0-763.0/(956.0-900.0)-(333.0-740.0)*(657.0+491.0*432.0+183.0/765.0/45.0)-303.0-254.0-706.0*(827.0-167.0*360.0+811.0)*52.0-9.0+230.0/(525.0+38.0-993.0)-(931.0/945.0*145.0)/(878.0*756.0*220.0*241.0/632.0)/939.0*621.0+(647.0+426.0-633.0/344.0+43.0*663.0/863.0*210.0*70.0+371.0-168.0)+423.0-559.0-(490.0+459.0)/714.0+873.0-(934.0*672.0)/53.0-(5.0*447.0/67.0+296.0+587.0/511.0+526.0+945.0*364.0)*98.0*(264.0-636.0)-928.0-961.0+575.0*579.0+424.0/211.0-958.0/344.0*902.0*95.0*(16.0+188.0+692.0*612.0/418.0+563.0/947.0*37.0)/731.0+605.0*(825.0+266.0)-(598.0*174.0*580.0+238.0)+59.0/527.0/60.0*711.0/(422.0+688.0)/459.0+341.0-825.0*683.0/(825.0*475.0/229.0)-790.0*358.0+570.0*(834.0-622.0*870.0)*(911.0/701.0/235.0/847.0)*488.0-542.0/296.0-166.0*2.0-563.0*(830.0+494.0/17.0*124.0)/161.0*144.0-712.0*420.0+(777.0-305.0/976.0)/(919.0-18.0)-(754.0-84.0+65.0)-17.0-100.0*(976.0*858.0/380.0)*154.0/(567.0*735.0)/(601.0/647.0/26.0-519.0+256.0*799.0*411.0/23.0+324.0*709.0*994.0-456.0*829.0-631.0+203.0+992.0/711.0+513.0/237.0-149.0*811.0-659.0*772.0+996.0+278.0)/967.0-502.0-755.0/(81.0/887.0-874.0)-152.0*228.0-(747.0-121.0)/464.0*167.0+(669.0-973.0)-175.0+373.0+664.0+(947.0+511.0/306.0/234.0/423.0*434.0*81.0*912.0)*115.0-(900.0*112.0+586.0/779.0)-(748.0*861.0/267.0+383.0-215.0-240.0)-980.0-(121.0/757.0-952.0)*(748.0/540.0/120.0)/407.0*(361.0-331.0/115.0/341.0)-(399.0+865.0-388.0)*690.0+(126.0*595.0)-(268.0+362.0)-95.0*495.0*143.0+24.0-(755.0/378.0/667.0)+857.0*155.0/813.0-113.0-800.0-(435.0+438.0+281.0+12.0*184.0/196.0)/651.0-866.0*989.0/89.0/823.0-232.0*895.0-(795.0/175.0)+335.0*(905.0-202.0-212.0+8.0/565.0/401.0+60.0)-247.0-(930.0+224.0-325.0+31.0)-(432.0*544.0)*67.0/876.0-323.0+453.0+(256.0+557.0*366.0/201.0)-96.0+793.0+(69.0-814.0)+464.0/148.0/(390.0*891.0-18.0*728.0*989.0*698.0+193.0)*676.0-745.0*932.0+782.0*660.0-127.0/51.0+713.0-(770.0*376.0-39.0)*66.0/767.0-508.0*(807.0/37.0)+915.0+(948.0+490.0/958.0/424.0/505.0-457.0)/(53.0-964.0-997.0+476.0/33.0)+(366.0+795.0)-929.0+511.0-234.0/263.0*641.0*629.0-(541.0/98.0*294.0+905.0*556.0*138.0/878.0+418.0)-(691.0-638.0+535.0+375.0)/123.0-450.0+623.0/943.0*524.0+404.0*598.0*54.0*(564.0*701.0/327.0)+327.0/(940.0-292.0+819.0)-762.0+684.0/443.0/176.0*757.0/351.0*(712.0*319.0*339.0+114.0-801.0/157.0-387.0-286.0*698.0+312.0)/509.0-(831.0+644.0*353.0)/261.0/698.0/470.0*(430.0/998.0/332.0/398.0)*663.0+456.0*37.0*993.0+(175.0+481.0+390.0)*981.0*410.0*(856.0-846.0)*920.0+17.0*523.0/(730.0-426.0/727.0)/(505.0+291.0)*421.0*228.0/17.0+625.0/949.0-284.0+221.0*689.0-(612.0/855.0-950.0)/702.0*238.0/132.0/719.0+207.0+(281.0+73.0/427.0*547.0)+693.0-874.0+(31.0-898.0/608.0/875.0)/821.0*748.0/(692.0+935.0/116.0)*(604.0-64.0)+934.0-70.0+839.0/793.0-(255.0+968.0/58.0-546.0)-550.0*857.0+134.0/(391.0*132.0)*199.0/56.0-506.0+417.0+790.0/(165.0/835.0)+373.0/865.0+594.0*577.0+(169.0*458.0)')

varpy = (223.0*114.0+967.0+665.0+273.0)/697.0*194.0*673.0*539.0-(613.0-514.0-971.0-76.0+946.0/156.0)*407.0*(300.0+701.0/887.0)+(975.0+691.0*422.0+61.0*661.0+930.0-650.0*269.0+886.0*939.0-685.0/732.0-696.0-845.0)*135.0-(266.0/93.0-692.0/200.0-194.0/124.0+422.0*998.0*120.0)/(605.0-170.0*344.0/16.0*330.0)/525.0*(660.0-601.0*232.0)-75.0-395.0-763.0/(956.0-900.0)-(333.0-740.0)*(657.0+491.0*432.0+183.0/765.0/45.0)-303.0-254.0-706.0*(827.0-167.0*360.0+811.0)*52.0-9.0+230.0/(525.0+38.0-993.0)-(931.0/945.0*145.0)/(878.0*756.0*220.0*241.0/632.0)/939.0*621.0+(647.0+426.0-633.0/344.0+43.0*663.0/863.0*210.0*70.0+371.0-168.0)+423.0-559.0-(490.0+459.0)/714.0+873.0-(934.0*672.0)/53.0-(5.0*447.0/67.0+296.0+587.0/511.0+526.0+945.0*364.0)*98.0*(264.0-636.0)-928.0-961.0+575.0*579.0+424.0/211.0-958.0/344.0*902.0*95.0*(16.0+188.0+692.0*612.0/418.0+563.0/947.0*37.0)/731.0+605.0*(825.0+266.0)-(598.0*174.0*580.0+238.0)+59.0/527.0/60.0*711.0/(422.0+688.0)/459.0+341.0-825.0*683.0/(825.0*475.0/229.0)-790.0*358.0+570.0*(834.0-622.0*870.0)*(911.0/701.0/235.0/847.0)*488.0-542.0/296.0-166.0*2.0-563.0*(830.0+494.0/17.0*124.0)/161.0*144.0-712.0*420.0+(777.0-305.0/976.0)/(919.0-18.0)-(754.0-84.0+65.0)-17.0-100.0*(976.0*858.0/380.0)*154.0/(567.0*735.0)/(601.0/647.0/26.0-519.0+256.0*799.0*411.0/23.0+324.0*709.0*994.0-456.0*829.0-631.0+203.0+992.0/711.0+513.0/237.0-149.0*811.0-659.0*772.0+996.0+278.0)/967.0-502.0-755.0/(81.0/887.0-874.0)-152.0*228.0-(747.0-121.0)/464.0*167.0+(669.0-973.0)-175.0+373.0+664.0+(947.0+511.0/306.0/234.0/423.0*434.0*81.0*912.0)*115.0-(900.0*112.0+586.0/779.0)-(748.0*861.0/267.0+383.0-215.0-240.0)-980.0-(121.0/757.0-952.0)*(748.0/540.0/120.0)/407.0*(361.0-331.0/115.0/341.0)-(399.0+865.0-388.0)*690.0+(126.0*595.0)-(268.0+362.0)-95.0*495.0*143.0+24.0-(755.0/378.0/667.0)+857.0*155.0/813.0-113.0-800.0-(435.0+438.0+281.0+12.0*184.0/196.0)/651.0-866.0*989.0/89.0/823.0-232.0*895.0-(795.0/175.0)+335.0*(905.0-202.0-212.0+8.0/565.0/401.0+60.0)-247.0-(930.0+224.0-325.0+31.0)-(432.0*544.0)*67.0/876.0-323.0+453.0+(256.0+557.0*366.0/201.0)-96.0+793.0+(69.0-814.0)+464.0/148.0/(390.0*891.0-18.0*728.0*989.0*698.0+193.0)*676.0-745.0*932.0+782.0*660.0-127.0/51.0+713.0-(770.0*376.0-39.0)*66.0/767.0-508.0*(807.0/37.0)+915.0+(948.0+490.0/958.0/424.0/505.0-457.0)/(53.0-964.0-997.0+476.0/33.0)+(366.0+795.0)-929.0+511.0-234.0/263.0*641.0*629.0-(541.0/98.0*294.0+905.0*556.0*138.0/878.0+418.0)-(691.0-638.0+535.0+375.0)/123.0-450.0+623.0/943.0*524.0+404.0*598.0*54.0*(564.0*701.0/327.0)+327.0/(940.0-292.0+819.0)-762.0+684.0/443.0/176.0*757.0/351.0*(712.0*319.0*339.0+114.0-801.0/157.0-387.0-286.0*698.0+312.0)/509.0-(831.0+644.0*353.0)/261.0/698.0/470.0*(430.0/998.0/332.0/398.0)*663.0+456.0*37.0*993.0+(175.0+481.0+390.0)*981.0*410.0*(856.0-846.0)*920.0+17.0*523.0/(730.0-426.0/727.0)/(505.0+291.0)*421.0*228.0/17.0+625.0/949.0-284.0+221.0*689.0-(612.0/855.0-950.0)/702.0*238.0/132.0/719.0+207.0+(281.0+73.0/427.0*547.0)+693.0-874.0+(31.0-898.0/608.0/875.0)/821.0*748.0/(692.0+935.0/116.0)*(604.0-64.0)+934.0-70.0+839.0/793.0-(255.0+968.0/58.0-546.0)-550.0*857.0+134.0/(391.0*132.0)*199.0/56.0-506.0+417.0+790.0/(165.0/835.0)+373.0/865.0+594.0*577.0+(169.0*458.0)
print('varpy  = ', varpy)

varcpp = 3904079446531.84
print('varcpp = ', varcpp)

print('varpy == varcpp?', varpy == varcpp)
print('math.isclose(varpy, varcpp, 1e-9, 1e-6)?', math.isclose(varpy, varcpp))
print()
#EEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE

'''
'''
