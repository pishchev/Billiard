#version 330

out highp vec4 fragColor;

uniform vec4 ambientColor;

uniform vec4 pointColor[4];
uniform vec4 pointPos[4];

uniform float ka;
uniform float kd;
uniform float ks;
uniform float k;
uniform float n;
uniform float p;

uniform vec4 camPos;

uniform sampler2D textureMap;
uniform sampler2D normalMap;

uniform sampler2D shadowMap[4];

in vec4 normals;
in vec4 fragPos;
in vec2 texCoords;
in vec4 fragPosLightSpace[4];

float far_plane = 60.0f;
float near_plane = 0.1f;

vec3 calcNormalFromNormalmap(vec3 localNormal,vec2 uv)
{
    vec3 n = normalize(localNormal.xyz);
    vec3 t = normalize(cross(n,vec3(1,1,1)));
    vec3 b = cross(n,t);

    vec3 normal = texture(normalMap , uv).rgb;
    normal = normalize(normal*2.0f - 1.0f);

    vec3 resultingNormal = normalize(normal.x*t+normal.y*b+normal.z*n);
    return resultingNormal;
}

float LinearizeDepth(float depth)
{
    float z = depth * 2.0 - 1.0; // Back to NDC
    return (2.0 * near_plane * far_plane) / ((far_plane - near_plane) - z * (far_plane - near_plane));
}

float ShadowCalculation(vec4 normal,vec4 lightDir , int i  )
{
    // perform perspective divide
    vec3 projCoords = fragPosLightSpace[i].xyz / fragPosLightSpace[i].w;
    // transform to [0,1] range
    projCoords = projCoords * 0.5 + 0.5;
    // get closest depth value from light's perspective (using [0,1] range fragPosLight as coords)
    float closestDepth = texture(shadowMap[i], projCoords.xy).r;
    // get depth of current fragment from light's perspective
    float currentDepth = 0.0 + LinearizeDepth(projCoords.z)/far_plane;
    // check whether current frag pos is in shadow
    float bias = max(0.05 * (1.0 - dot(normal, lightDir)), 0.005);
    //float shadow = currentDepth - bias > closestDepth  ? 1.0 : 0.0;


    float shadow = 0.0;
    vec2 texelSize = 1.0 /textureSize(shadowMap[i], 0);
    for(int x = -1; x <= 1; ++x)
    {
        for(int y = -1; y <= 1; ++y)
        {
            float pcfDepth = LinearizeDepth(texture(shadowMap[i], projCoords.xy + vec2(x, y) * texelSize).r)/far_plane;
            shadow += currentDepth - bias > pcfDepth ? 1.0 : 0.0;
        }
    }
    shadow /= 2.0;

    return shadow;
}

void main()
{
    vec4 actualNormal  = vec4(calcNormalFromNormalmap(normals.xyz, texCoords),1);
    //vec4 actualNormal = normals;

    //ambient
    vec4 col =ka* ambientColor;

    //--------------- Point -----------------//

    for (int i =0 ; i < 4 ; i++)
    {

        vec4 lightDir = normalize(pointPos[i] -fragPos);

        float shadow = ShadowCalculation(normals,normalize(pointPos[i] -fragPos) , i);
        //shadow = 0;

        float distansFactor = 1/(pow(distance(fragPos , pointPos[i]),p) + k);

        float distansShadow = 300000/pow(distance(fragPos , pointPos[i]),4);

        //specular point
        col += ks*distansFactor *
                pow(max(dot( normalize(2*actualNormal - lightDir),normalize(camPos - fragPos)),0),n)*
                pointColor[i]*
                max(dot(actualNormal, lightDir),0)*
                (1 - min(shadow*distansShadow,1));

        //diffuse point
        col += kd* distansFactor*
                max(dot(lightDir,actualNormal),0)*
                pointColor[i]*
                (1 - min(shadow*distansShadow,1));
    }

    fragColor = texture(textureMap, texCoords) * col;

}
