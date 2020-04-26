sampler samp;//采样
//sampler samp1;//采样

matrix matWorld;//变换矩阵
float4 matTran;//平移矩阵

//输入纹理坐标(所有)
struct PS_INPUT {
	float2 t0 : TEXCOORD0;//输入纹理坐标UV
	//float2 t1 : TEXCOORD1;//输入纹理坐标UV
	vector color : COLOR;//颜色
};

//运算后输出
struct PS_OUTPUT {
	vector color : COLOR0;
};

struct ColorMatrix {
	row_major float4x4 mat;
	float4 offset;
};

float4 ColorTransform(float4 color, ColorMatrix mat)
{
	return mul(color, mat.mat) + mat.offset;
}

PS_OUTPUT main(PS_INPUT input)
{
	//初始化
	ColorMatrix mat;
	mat.mat = matWorld;
	mat.offset = matTran;

	//输出
	PS_OUTPUT output = (PS_OUTPUT)0;

	//UV坐标-获取纹理采样颜色值
	float4 color = tex2D(samp, input.t0);
	//float4 color1 = tex2D(samp1, input.t1);

	//颜色矩阵计算
	//color = color * color1;
	color = ColorTransform(color, mat);

	//设置输出颜色
	output.color = color;

	return output;
}