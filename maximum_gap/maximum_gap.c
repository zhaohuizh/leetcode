#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
/*
 This solution does not pass the test online. But I ran the failed test
 input as below and get the correct result.
*/
int maximumGap(int num[], int n) {
  if(n == 1) return 0;
  int min = INT_MAX, max = 0;
  int i;
  for(i = 0; i < n; i++){
    if(num[i] > max){
      max = num[i];
    }
    if(num[i] < min){
      min = num[i];
    }
  }
  if(max == min) return 0;
  int gap_size = (max - min) / (n - 1);
  if(gap_size == 0) gap_size = 1;
  int *max_bucket = (int *) malloc(sizeof(int) * n);
  int *min_bucket = (int *) malloc(sizeof(int) * n);
  int res = 0;
  for(i = 0; i < n; i++){
    int index = (num[i] - min)/gap_size;
    if(index >= n) index = n - 1;
    if(min_bucket[index] == 0){
      min_bucket[index] = num[i];
      max_bucket[index] = num[i];
    }
    if(num[i] > max_bucket[index]){
      max_bucket[index] = num[i];
    }
    if(num[i] < min_bucket[index]){
      min_bucket[index] = num[i];
    }
  }
  int prev_max = max_bucket[0];
  for(i = 0; i < n; i++){
    if(min_bucket[i] != 0){
      if(min_bucket[i] - prev_max > res){
        res = min_bucket[i] - prev_max;
      } 
      prev_max = max_bucket[i];
    }
  }
  return res;
}

int main(){
  int num[] = {941567,201768,626216,902189,393390,306106,710387,146166,328000,917915,395960,932868,464909,169090,306500,392796,626875,808575,710700,618240,623090,745155,741393,302175,550370,195570,264500,229872,922378,827000,526430,801980,581180,251196,618275,117944,370256,285128,919384,601704,270122,584671,895982,288252,108736,826368,607612,228460,522826,67350,773852,742852,989345,956989,572515,925750,775280,219682,651750,539036,315968,723538,67280,272107,847054,244534,12544,303425,242428,488721,509660,458280,90600,216476,600709,808666,813045,501533,40971,656100,650640,497765,84500,555765,156367,883082,214880,931306,507490,262824,133182,82548,783848,440213,274116,42250,867392,108932,945115,339300,256300,902706,226272,681443,543615,572883,704387,211075,329792,145355,770740,71532,91560,401250,354316,440140,968509,193068,497010,77902,79910,129424,826856,446700,145637,140335,942155,409664,973675,390320,57592,535530,591575,502148,369752,14028,751470,682704,930707,594274,230735,726756,492625,816570,450640,991640,553844,471148,877993,982544,819175,980952,844208,589344,479832,103915,301430,184230,635864,108446,436837,15696,579884,81232,589222,74,396840,121328,155458,778907,458454,325541,488202,713653,984628,89700,767571,313040,97120,250296,169501,369720,473823,353888,849911,655699,942352,394267,883552,810360,614252,280705,95560,688458,720854,910600,240895,834253,844672,343698,39432,50621,875420,264591,805246,693110,768232,801871,236150,272914,883680,228400,334070,757381,561500,266640,256800,905600,605034,810042,745082,84451,468996,608059,389627,722520,337408,4672,315440,371826,487152,286663,816833,409307,55923,799232,691192,992830,11682,981760,743257,235555,759552,285510,490321,664108,967354,162248,183792,541416,640480,267144,568905,454738,600089,328172,15040,287604,661740,732394,49384,793980,711640,129528,281245,308727,838486,61860,420032,990146,823056,760625,262288,6121,201996,695688,90420,139784,172484,237804,806788,144560,941414,100420,355176,674465,562542,152540,838128,5390,620725,667490,100376,281780,361150,558266,642000,448375,205444,424240,254929,549862,570428,910640,229581,211056,244928,839488,644988,884580,121780,257204,12750,121180,690610,125761,715580,180014,755754,838200,15926,685272,754576,601416,182410,890950,798528,457994,658526,825696,245510,637355,229524,592042,506743,989584,242534,568302,544255,404014,5182,150119,256446,492020,90434,817047,302352,91750,851426,977532,15044,152076,938302,506160,240862,184,475161,284496,472773,202747,422790,340235,969323,890484,914904,891980,266996,967650,909336,610888,691666,228888,919056,752084,784889,894094,114480,695284,22754,239494,317293,786218,432264,330400,81504,62600,288175,886859,895450,819902,238464,649111,939456,45608,784852,668650,85622,956815,694457,92408,932384,781114,774197,248121,525770,465220,70245,845372,825307,782321,333404,184136,74744,859152,161387,315317,917952,921430,31120,315510,734946,98097,470332,19816,833034,236419,177200,290502,308310,401700,130948,81995,423280,798197,873160,591020,481347,551040,818848,497299,267628,185328,237435,531496,912984,734035,267817,468635,20217,786316,161220,34590,764828,668844,995648,434689,424339,511373,591318,46599,466327,42546,738976,902208,376080,468041,848472,125120,480175,488704,616192,183215,563381,170781,260644,240020,674472,760628,153968,695998,535934,579632,246000,919696,356891,603975,94576,312840,857463,115235,174230,437564,671269,834096,929290,361911,543162,153605,656640,530642,365340,79618,755320,521728,855230,225320,968982,126160,466449,809450,884572,829760,66576,258615,786614,437184,975609,587999,241166,534024,442046,294811,827600,416500,505624,204535,457380,571072,26474,468024,634480,329148,888749,974000,183660,818560,662328,171576,684244,556530,175070,433068,732712,21082,628334,215473,476040,207087,412225,823508,435828,444730,357582,370095,966816,503375,997838,86272,58230,59599,36392,528458,533679,576628,236348,241360,65160,595500,517157,33024,913856,780956,562704,40972,280046,330517,689125,757578,968640,810188,569322,204747,615689,161008,629008,555628,102683,758995,700621,908000,227307,986621,33721,891760,235814,406276,996800,526290,234708,16040,443296,181456,692210,752834,150580,471475,37516,979232,98548,636020,266765,772133,119544,20968,528442,652000,764621,97219,673644,653956,878507,335545,61476,98196,598484,75902,922808,503892,678500,123728,976651,690592,261613,261906,210725,188410,755440,778784,144438,416552,870656,211612,723480,502976,947758,384691,894251,655499,128204,669352,901905,171976,173290,190231,470985,565699,31490,156250,469066,890684,77500,529099,769104,549024,955166,240700,190945,886255,148082,337662,416280,258016,43618,219012,20832,60800,915172,414540,299775,936912,601160,241931,616845,760040,188492,209559,557010,790554,911794,519540,453635,614912,561146,278140,373340,40242,326321,455175,847408,937455,466740,222996,426400,376090,549057,449080,737618,372500,556170,709675,946756,726969,680170,958725,539568,350175,696600,534020,268480,736598,462555,438578,746302,534475,724396,812896,737850,672420,647496,809668,427254,55200,257102,74650,17782,798258,143160,595403,71448,778894,386134,790840,80175,628400,79304,416811,659118,971145,460378,232724,403554,555790,167944,766000,37776,486512,385555,792488,968546,970440,642002,897474,49016,686035,352382,935315,915625,492560,496912,906965,761235,857060,584656,722692,355428,490024,258734,248711,245172,5688,941459,38508,807424,574054,142710,798302,864780,275283,516382,36574,688850,186705,601248,119210,962627,728644,69356,660774,400300,413472,304680,698555,214975,185024,470587,501912,699840,221084,755062,667335,230697,494915,344870,104696,42298,665580,636806,221563,730182,417841,61760,636372,591408,543392,158060,970478,488248,536234,872372,835920,970812,46035,906765,152947,908288,362816,800680,85572,719476,389268,900184,176560,415751,961691,738112,86140,400854,503550,155520,266776,548964,670528,727250,42089,319212,555567,190106,394090,515430,105503,245726,141080,33233,16800,540494,339495,272807,580960,902940,52212,381908,791712,687495,301371,516416,297664,179880,590425,927364,48465,846933,76048,183388,476940,741436,10181,492928,413457,783946,729901,909876,694880,565200,764674,223294,457672,661852,309375,203530,335996,79866,548880,823517,306055,738124,783080,687553,275212,602232,101250,45870,286818,942431,360700,21250,309548,866745,666441,442304,65543,496469,590625,743970,107106,410340,362244,661088,119084,900870,414750,763530,48842,98200,135248,930593,906880,364910,526515,96541,333304,939216,570075,595614,29622,61340,5380,338022,655070,544021,808080,154268,517178,770216,69048,504300,847357,29984,491353,910897,441753,941610,792065,119152,564979,870512,587940,322730,731478,354206,854574,838220,596055,809523,786976,409602,790440,429264,180750,988800,628945,90472,704692,971527,383914,738999,246805,294247,475145,149680,37498,293750,737479,357230,89802,606908,709198,506782,91034,94796,585280,486505,599411,528814,733233,81330,67335,307690,472309,602482,772112,956117,693582,710385,109710,240742,248404,852107,722710,2550,79808,63846,464813,270624,53624,945460,121546,146520,741648,360600,433905,563818,440530,465621,64446,691575,911538,58112,766508,800378,962144,574125,802715,237670,226442,715000,355872,180102,420430,341250,444070,923714,59664,585712,238110,466522,128970,439980,454400,937909,932110,251118,757640,732861,921580,245800,952127,593930,639935,251464,532393,417422,197886,612120,97304,835237,85016,160790,816,735463,857655,861270,145734,909075,460290,431575,735667,701667,721000,368536,938504,469392,478726,508405,776320,837888,303104,297116,130850,893076,40540,876330,455424,63404,310170,315620,434629,773392,421864,475414,597291,495893,616872,865314,335350,745505,127242,547897,987632,872960,600270,213780,725854,950760,751178,676611,190786,180876,524604,537502,790707,103512,298678,261807,781768,178452,403006,706300,133440,497273,537688,32784,968670,765590,415534,511471,81616,58578,74569,405664,863814,440576,675520,117512,548562,921335,574850,75204,243781,545768,185570,13298,737586,290888,342700,473073,30622,593692,309824,408120,721030,64320,569120,852896,888270,230275,81922,711840,883584,36275,595756,51331,392869,579390,349461,343912,125458,975144,734203,572509,105686,530384,150144,741950,668283,510014,865538,911493,760640,201210,430816,411452,631866,899585,791365,606047,319628,581670,338665,234700,413795,420910,807860,563715,994346,459260,41043,395600,928983,410818,450736,132870,639594,663189,285448,120815,323412,681937,466824,201052,527360,353788,286721,900240,635164,684659,497910,338676,946340,663540,132300,187860,49648,68302,272108,952564,213800,30736,858136,639128,604984,864648,535025,348946,690912,779400,429324,349327,661755,77624,393050,618180,332795,771746,34950,880724,745975,391380,750554,979720,22225,183829,607126,682412,419716,317145,560586,923134,238912,230305,900904,248400,235520,362282,44013,99595,976260,662298,484304,476896,345404,595291,920442,801975,642284,341164,815919,809200,370904,506409,229781,756500,702900,214250,288986,831971,310988,623536,603560,635360,391514,206802,186380,83801,262162,373066,757776,468276,763005,78460,901662,732370,196582,740158,223178,607192,105841,525874,751512,603723,521696,888280,907590,184275,314408,75453,391800,523476,63400,958574,348484,273231,31890,982680,30125,706088,257938,737734,453665,521950,373564,353330,667622,427722,568748,848000,655424,720774,441436,445882,153072,343518,788735,938808,584976,545248,674900,83395,383444,683569,802748,505220,679192,223241,505460,43769,737976,615335,701230,467445,734564,573140,662587,91320,364640,320341,587819,803136,163820,418242,783236,933780,27516,376816,216274,43654,196520,799600,743332,16364,24592,62128,282205,386576,755270,869984,391946,217180,277580,185960,359608,761276,176252,871771,981304,479030,515716,908768,845300,52548,379900,262188,995550,621026,328406,494410,898216,771282,598542,346208,291863,891045,109668,306600,44857,27064,330409,588895,929671,625734,411314,451444,563008,165610,116800,949943,186816,700252,751815,138624,116626,858068,863784,272660,498242,367910,454578,787142,190950,591192,723732,553920,271424,546066,336372,472128,121000,323424,595205,848523,553240,84769,249570,606336,440416,339725,769476,642579,640458,190763,139250,484588,998770,966154,119700,35708,553744,318862,902288,772621,555264,218802,884535,722380,672768,45950,721908,351728,26741,891293,964402,851520,640838,215786,337544,256040,269790,26070,684896,449616,506720,344041,588872,856360,478275,889000,408948,770032,930254,868682,62788,456897,599765,130339,322888,158620,235828,747758,866325,860356,465900,319160,978292,86854,643510,59503,910184,521480,317400,532875,668876,343242,268496,936304,129620,646804,389842,309214,338229,360920,451640,196950,244586,46312,847400,861328,554015,36904,897372,665027,729728,897784,535932,59740,161951,325688,44833,760820,834060,738009,714345,613411,249310,208224,555453,231040,563079,481490,718530,661016,647956,217420,219800,783695,108985,381268,208745,323840,350657,813276,760499,398784,423918,999234,237428,417741,763360,752167,854341,358055,521019,766926,793520,217700,260968,201168,145960,597958,751786,884208,279630,970898,864500,366412,408528,279680,3010,117587,751972,183461,712650,455125,994889,244928,559260,186332,646428,905112,133328,691905,668086,667356,670190,881419,352130,309182,153744,588560,486208,329592,341960,743695,432675,742568,867226,449188,804382,682180,626592,543600,696825,264659,695367,101335,175229,355386,55526,642744,249588,819014,907000,53675,838217,771250,344170,995104,332114,458185,21719,919876,488920,186639,287750,601058,296238,334950,167905,597041,31456,0,428592,444770,43355,538090,331072,745320,301812,641920,592605,150308,502060,616910,183706,775555,432650,424216,90194,990000,927674,649088,909770,661318,320126,842960,231999,620170,688902,280200,258342,621725,335724,330123,175250,332968,642970,551006,634154,556472,541990,524970,332582,472771,556776,472851,229584,192371,581242,200000,850449,182520,193120,859800,647916,481632,976800,244400,133506,686732,942280,53576,838320,550513,59214,687032,279515,873254,82576,44300,888825,487450,541802,188440,524515,305448,703428,73936,92820,724180,287425,577444,414363,907240,718367,115136,412760,719091,435420,893563,195000,665585,449163,586658,6566,457816,170685,672312,978050,81852,150520,529972,517030,204840,222750,399552,791360,665760,563630,316250,483800,224956,998232,772520,805659,346240,235125,15860,932546,781210,745812,341432,574636,583477,895872,584237,391933,62928,35080,741560,223225,852595,386748,563156,385552,801168,535428,221737,835655,276698,407320,385640,554208,221112,708512,683040,126160,799340,589934,139632,834439,348480,394484,787431,935535,226304,999758,657344,922710,274160,262323,500935,34614,447568,63199,443398,575284,558265,930060,162446,912725,772024,264650,342704,691755,562527,366479,199536,962728,741246,84720,620305,814370,416656,930945,186810,391200,624178,993480,670456,122421,234524,135402,646910,550246,216274,2232,836896,425765,799523,850620,215112,283918,909580,618998,328000,516389,697313,959903,966217,122984,743608,798160,428490,651677,514952,707988,559115,648080,165158,573275,930496,91712,993337,534080,434360,2915,515154,646734,707200,756630,878125,14534,691878,648264,558984,363573,776565,17003,457490,440224,654114,398800,116145,92859,271967,25932,118608,549500,175940,175368,996924,117856,265728,437097,210840,753394,997238,807019,428521,953613,459644,266556,654796,866624,492500,954256,78863,991417,936905,626550,477634,698437,505364,114909,374986,321040,126292,323736,472496,573330,816910,573262,813570,884330,791792,21936,808976,996072,734579,650543,400351,496204,313564,643509,916980,697439,405063,173240,323750,11206,629600,452270,727291,21100,624569,810955,804096,990633,460450,132208,740416,848717,249910,516764,480915,39254,866603,910145,807744,183474,787386,801180,982830,174460,205640,687240,832836,348516,623136,685704,621517,875325,634240,343488,899916,984444,717336,511818,339834,683025,504409,16774,369350,926142,704416,586528,608743,623571,315933,787007,551191,878525,983736,503992,493292,495410,801572,64463,109408,855017,528032,541170,359268,393130,172336,523348,687292,89546,744907,867110,150277,505776,189845,540138,383536,314240,129152,210274,715802,344518,114253,131365,953062,649148,910354,959176,884676,497055,180892,319000,382128,826375,78520,739156,203192,172855,720255,762642,916262,198928,2235,552822,570574,480940,689840,601396,796547,93820,168765,443608,957126,776394,317184,803425,599774,152863,683039,463995,736746,124300,500916,144140,196175,599950,41107,805052,356397,409098,509096,794520,346070,58832,829523,593573,357092,126402,496622,929126,767866,84156,919510,736533,212860,562650,973928,738376,352231,16285,671668,890749,694188,997325,230631,925474,102608,506480,344000,491844,548060,181098,216288,11428,458042,378472,427232,917516,834170,963424,22154,699712,965900,838316,729854,827736,573629,959251,771680,809496,781410,31071,198328,771710,787613,618028,556788,403008,997102,712527,392248,17172,322317,790144,445456,139368,394138,248094,565260,626775,529665,38193,535008,145778,64496,345216,561702,158384,876860,596554,239294,491729,510968,350850,320836,540270,632116,872040,295341,507153,204700,853398,547490,658492,197420,505152,707004,787532,251008,757056,286810,109832,982688,677692,275203,377038,920608,661436,664441,925630,292600,892350,232000,686644,356024,136229,574203,111668,833920,430292,689767,806150,655956,178400,149736,937391,14681,901614,205793,669066,466650,795896,281762,918778,518752,393555,485749,963119,405785,163274,508053,84572,759910,421596,695932,362120,12041,884441,783380,687700,48416,437390,70288,946016,617571,897037,390950,72324,525250,152096,898043,749048,103003,38551,475750,732000,520080,767552,225271,960158,914430,772335,233860,912749,539000,93275,786910,560595,395424,704712,632664,547221,932531,898867,705146,787384,758496,340320,357125,599843,541632,583616,524892,80485,191276,840957,651576,41284,815500,449524,975530,567640,893644,594611,553455,125399,889842,709860,669688,186848,544854,390032,688100,355400,964646,868042,514376,564620,128621,504149,355936,916960,27210,460240,229960,721070,991717,888212,771888,713104,813895,337060,841734,214138,64460,784100,489984,708480,641918,199478,888964,926625,634550,48800,738455,129364,435442,178552,234563,720818,633996,229339,443748,594138,871378,35284,67675,990236,55490,672000,751728,243939,821300,12037,450492,501560,401349,11500,108384,576685,673072,729220,912453,937796,895360,903277,313570,657971,525105,4184,814794,32203,635222,428834,154423,519908,308040,389720,849321,107741,198720,43156,327745,755025,625020,125036,821040,664570,124843,518912,31416,591265,778263,175883,777616,176920,890502,992595,267160,896185,670576,944900,425320,3855,84212,581214,463930,665260,827600,617973,839486,586652,123218,559896,684176,543601,360580,133576,546922,620680,871560,716335,399740,239864,104496,221804,53771,327958,654039,892890,267498,769717,462664,890692,423506,589607,643690,30160,626686,933184,75709,959329,794335,50951,55740,92116,573642,710400,216500,287909,237201,283459,890504,471465,621114,135765,138262,769410,421404,891520,825994,46293,600931,603032,24356,891480,506015,168228,703994,438746,897256,167560,981352,591104,108678,754480,365214,830631,960474,56041,22080,759162,267176,257066,802192,161607,677346,900704,886866,56410,898464,520780,19650,537000,343750,873096,402675,344002,936217,456798,695186,438955,570049,870640,661587,613752,100128,960300,640279,589200,912750,382338,317694,812840,510350,500425,894970,745875,545676,815709,846809,816355,933791,204079,309011,664966,564312,74482,235500,886596,58880,467670,21163,849424,314134,759950,872655,461906,784745,423680,588480,239756,963087,38563,78128,735186,55168,495061,515079,799291,44154,763035,75773,310106,773320,322360,601024,684560,747630,534650,947570,181088,331260,943060,161456,446,495863,892729,130924,215107,694478,46820,988029,80832,334783,880155,406032,503958,123264,993768,559400,514384,179124,120457,487000,395346,49496,854089,725665,386570,328367,226448,172899,996105,358804,990850,492800,722944,616880,686642,459732,870664,477606,48305,579550,303332,347815,409720,661363,732350,624185,901033,72075,432959,434800,774125,903840,649286,894986,821968,909434,302460,466312,37200,325116,767552,74368,719237,212875,621312,425570,92599,823145,111712,172823,970316,669640,361802,914530,898415,466830,23288,796856,972532,584609,232128,215749,644625,779486,544259,976583,700928};
  int res = maximumGap(num, sizeof(num)/sizeof(num[0]));
  printf("%d\n", res);
}
